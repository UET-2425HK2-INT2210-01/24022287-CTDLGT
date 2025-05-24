class Stack
    array S[capacity]
    top ← -1

function push(x)
    if top = capacity - 1 then error "Stack Overflow"
    top ← top + 1
    S[top] ← x

function pop()
    if top = -1 then error "Stack Underflow"
    x ← S[top]
    top ← top - 1
    return x

function peek()
    if top = -1 then error "Stack Empty"
    return S[top]

function isEmpty()
    return top = -1
