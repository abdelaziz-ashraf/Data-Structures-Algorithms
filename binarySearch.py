def binary_search(list, item):
  low = 0
  high = len(list)-1

  while low <= high:
    mid = (low+high)//2
    if item == list[mid]:
      return mid
  
    if item < list[mid]:
      high = mid - 1
    else:
      low = mid + 1
  return None;


my_list = [1, 2, 3, 5, 7, 9, 15, 50]
print(binary_search(my_list, 3))
print(binary_search(my_list, 10))
