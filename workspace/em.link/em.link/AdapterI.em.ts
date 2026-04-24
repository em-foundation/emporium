import '@$$emscript'
export const $U = $declare('INTERFACE')

import * as T from '@em.link/Types.em'

export interface em$meta { }

export interface $I {
    em$meta: em$meta
    recvMsg(on_done: T.RecvDoneFxn): void
}

/*

package em.rf.core

import Dev
import SockPkt

interface SockAdapterI

    const RX_TIMEOUT: uint16 = 2000
    
    function getMsg(): SockPkt.Message&
    function recvMsg(onDone: Dev.RecvDoneFxn)
    function sendMsg(msg: SockPkt.Message&, onDone: Dev.SendDoneFxn)
    function setPeer(addr: Dev.Addr&) 

end

*/
