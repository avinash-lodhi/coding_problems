###
# Problem description: Find a peak in 2D matrix
###
def find_max(arr):
    """
    Find and return the index of max element of the given column
    """
    max = arr[0]
    return_val = 0
    for index, num in enumerate(arr):
        if max < num:
            max = num
            return_val = index
    return return_val


def find_peak(matrix, start, end):
    """
    Mehtod to find the peak element
    """
    if start > end:
        return None
    mid = int((start+end)/2)
    max = find_max(matrix[mid])
    if mid == 0:
        return matrix[mid][max] if matrix[mid][max] > matrix[mid+1][max] else None
    if mid == len(matrix[0])-1:
        return matrix[mid][max] if matrix[mid][max] > matrix[mid-1][max] else None
    if matrix[mid][max] < matrix[mid-1][max]:
        return find_peak(matrix, start, mid-1)
    if matrix[mid][max] < matrix[mid+1][max]:
        return find_peak(matrix,mid+1,end)
    return matrix[mid][max]


def main():
    print(find_peak([[1,2,3,2,1],[1,2,4,3,2],[2,1,3,2,1]],0,2))
    print(find_peak([[4,2,1,2,1],[3,2,1,2,2],[2,1,3,2,1]],0,2))
    print(find_peak([[1,2,3,2,1],[1,2,1,3,2],[2,1,3,2,4]],0,2))
if __name__ == '__main__':
    main()