class Node
    value
    next

class Stack
    top ← null

function push(x)
    newNode ← new Node(x)
    newNode.next ← top
    top ← newNode

function pop()
    if top = null then error "Stack Underflow"
    x ← top.value
    top ← top.next
    return x

function peek()
    if top = null then error "Stack Empty"
    return top.value

function isEmpty()
    return top = null

