# Selection Sort Algorithm
#
# This algorithm sorts an array by repeatedly finding the minimum element from the unsorted part and putting it at the beginning.
#
# Parameters:
# - array: The array to be sorted.
#
# Returns:
# - The sorted array.

def selection_sort(array)
  n = array.size
  (0...n-1).each do |i|
    min_index = i
    (i+1...n).each do |j|
      min_index = j if array[j] < array[min_index]
    end
    array[i], array[min_index] = array[min_index], array[i] if min_index != i
  end
  array
end

def test_selection_sort
  array = [64, 34, 25, 12, 22, 11, 90]
  sorted_array = selection_sort(array)
  puts "Sorted array: #{sorted_array}"
end

test_selection_sort
