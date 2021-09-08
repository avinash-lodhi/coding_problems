###
# Problem description: Find a peak in a given array
###
def find_peak(arr,start,end):
    if start>end:
        return None
    mid = int((start+end)/2);
    if mid == 0:
        return arr[mid] if arr[mid] > arr[mid+1] else None
    if mid == len(arr)-1:
        return arr[mid] if arr[mid] > arr[mid-1] else None
    if arr[mid] < arr[mid-1]:
        return find_peak(arr,start,mid-1)
    if arr[mid] < arr[mid+1]:
        return find_peak(arr,mid+1,end)
    return arr[mid]
    
def main():
    print(find_peak([1,2,3,4,5,6,7,8],0,7))
    print(find_peak([8,7,6,5,4,3,2,1],0,7))
    print(find_peak([10,15,4,8,5,14,5],0,6))

if __name__ == '__main__':
    main()