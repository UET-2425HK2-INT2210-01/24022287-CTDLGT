class Node
    value
    next

class Queue
    front ← null
    rear ← null

function enqueue(x)
    newNode ← new Node(x)
    if rear = null
        front ← rear ← newNode
    else
        rear.next ← newNode
        rear ← newNode

function dequeue()
    if front = null then error "Queue Empty"
    x ← front.value
    front ← front.next
    if front = null then rear ← null
    return x

function peek()
    if front = null then error "Queue Empty"
    return front.value

function isEmpty()
    return front = null

