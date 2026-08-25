import '@$$emscript'
export const $U = $declare('MODULE')

class Child extends $struct {
    value: u32
}

class Parent extends $struct {
    child_ref: $$<Child>
    child: Child
}

var parent_tab = $table<Parent>()

export namespace em$meta {
    export function em$construct() {
        const p = parent_tab.$$add()

        p.$$.child.value = 0x12345678

        // This is the capability we're testing:
        p.$$.child_ref = $$(p.$$.child)
        console.log('p')
        console.log(p)
        console.log('child')
        console.log(p.$$.child)
        console.log('child_ref')
        console.log(p.$$.child_ref)


    }
}

//>> ---- em$targ ---- <<//

export function em$run() {
}

