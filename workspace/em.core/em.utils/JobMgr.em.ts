import '@$$emscript'
export const $U = $declare('MODULE')

import * as FiberMgr from '@em.utils/FiberMgr.em'

export const NUM_ARGS = 4

export enum State {
    IDLE,
    RUNNING,
    COMPLETE,
}

export type Body = cb_t<[]>
export type Obj = $$<Job>

export class Args extends $vector<arg_t> {
    $len = NUM_ARGS
}

class Job extends $struct {
    _args: Args
    _body: Body
    _fiber: FiberMgr.Obj
    _state: volatile_t<State>
}
interface Job {
    args(this: Job): $$<Args>
    start(this: Job): bool_t
    state(this: Job): State
}

var job_tab = $table<Job>()

export namespace em$meta {
    export function create(body: Body): Obj {
        const job = job_tab.$$add()
        const fiber = FiberMgr.em$meta.create($cb(jobFB), job_tab.$len - 1)
        job.$$._body = body
        job.$$._fiber = fiber
        job.$$._state = State.IDLE
        for (const i of $range(NUM_ARGS)) {
            job.$$._args[i] = 0
        }
        return job
    }
}

//>> ---- em$targ ---- <<//

function jobFB(a: arg_t) {
    const job = $$(job_tab[<u16>a])
    job.$$._body()
    job.$$._state = State.COMPLETE
}

Job.prototype.args = function (this: Job): $$<Args> {
    return $$(this._args)
}

Job.prototype.start = function (this: Job): bool_t {
    if (this._state == State.RUNNING) return false
    this._state = State.RUNNING
    this._fiber.$$.post()
    return true
}

Job.prototype.state = function (this: Job): State {
    return this._state
}
