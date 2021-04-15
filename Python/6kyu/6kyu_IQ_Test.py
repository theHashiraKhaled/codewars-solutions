def iq_test(numbers):
    #your code here
    numbers = [int(x) for x in numbers.split()]
    even = []
    odd = []
    for i in numbers:
        if i % 2:
            even.append(i)
        else:
            odd.append(i)
    return numbers.index(odd[0]) + 1 if len(even)>len(odd) else numbers.index(even[0]) + 1
