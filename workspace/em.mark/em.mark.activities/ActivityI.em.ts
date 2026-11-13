import '@$$emscript'
export const $U = $declare('INTERFACE')

// setup/teardown run once per campaign, outside the Debug D measurement.
// exec must complete the entire measured activity before returning.
export interface $I {
    setup(): void
    exec(): void
    teardown(): void
}