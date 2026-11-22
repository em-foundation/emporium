import '@$$emscript'
export const $U = $declare('INTERFACE')

export interface $I {
    setup(): void
    exec(): void
    report(): void
    teardown(): void
}