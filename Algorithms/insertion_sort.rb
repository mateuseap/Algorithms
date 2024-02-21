# Insertion Sort Algorithm
#
# This algorithm sorts an array by iteratively inserting each element into its correct position in a sorted sublist.
#
# Parameters:
# - array: The array to be sorted.
#
# Returns:
# - The sorted array.

def insertion_sort(array)
  n = array.size
  (1...n).each do |i|
    key = array[i]
    j = i - 1
    while j >= 0 && array[j] > key
      array[j + 1] = array[j]
      j -= 1
    end
    array[j + 1] = key
  end
  array
end

def test_insertion_sort
  array = [64, 34, 25, 12, 22, 11, 90]
  sorted_array = insertion_sort(array)
  puts "Sorted array: #{sorted_array}"
end

test_insertion_sort
