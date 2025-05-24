C1: function powerOfTwo_iterative(n)
    result ← 1
    for i ← 1 to n
        result ← result × 2
    return result

C2:function powerOfTwo_recursive(n)
    if n = 0 then return 1
    if n mod 2 = 0
        half ← powerOfTwo_recursive(n / 2)
        return half × half
    else
        return 2 × powerOfTwo_recursive(n - 1)
