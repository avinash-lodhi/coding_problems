###
# Problem Description:
###

def can_place_top(tuple1, tuple2):
    """
    Method to check if the block can be placed at top
    Returns boolean value
    """
    a,b,c = tuple1
    x,y,z = tuple2
    if a == None and b == None and c == None:
        return True
    return a>x and b>y and c>z

def place_blocks(block_arr):
    """
    Method to place blocks so that they return the max height
    """
    top = (None, None, None)
    height = 0
    return placed_blocks(top,height,block_arr)

def placed_blocks(top,height,block_arr):
    """
    Recursive method to return the max height
    """
    if block_arr==[]:
        return height
    
    max_height = 0
    l = len(block_arr)
    for idx in range(l):
        box = block_arr[idx]
        block_arr.remove(box)
        cur_height = placed_blocks(box,height+box[2],block_arr) if can_place_top(top,box) else placed_blocks(top,height,block_arr)
        block_arr.insert(idx,box)
        max_height = cur_height if cur_height > max_height else max_height
    return max_height

if __name__ == '__main__':
    print(place_blocks([(1,2,3),(4,5,6),(7,8,9),(3,2,1),(5,6,4)]))