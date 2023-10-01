def binary_search(input_array, value):
    """Your code goes here."""
    lo = 0
    hi = len(input_array) - 1
 
    # This below check covers all cases , so need to check
    # for mid=lo-(hi-lo)/2
    while hi - lo > 1:
        mid = (hi + lo) // 2
        if input_array[mid] < value:
            lo = mid + 1
        else:
            hi = mid
 
    if input_array[lo] == value:
        return lo+1
    elif input_array[hi] == value:
        return hi+1
    else:
        return -1