# Binary Search Algorithm
# 
# This algorithm searches for a target value in a sorted array. It repeatedly divides the search interval in half until the value is found or the interval becomes empty.
# 
# Parameters:
# - array: The sorted array to search in.
# - k: The target value to search for.
# - n: The size of the array.
# 
# Returns:
# - The index of the target value if found, otherwise -1. 

def binary_search(array, k, n)
  l = 0
  r = n - 1

  while l <= r
    m = (l + r) / 2

    if k == array[m]
      return m
    elsif k < array[m]
      r = m - 1
    else
      l = m + 1
    end
  end

  return -1
end

def test_binary_search
  array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]

  puts "Searching for 5 in the array: #{binary_search(array, 5, array.size)}"
  puts "Searching for 13 in the array: #{binary_search(array, 13, array.size)}"
  puts "Searching for 20 in the array: #{binary_search(array, 20, array.size)}"
end

test_binary_search

