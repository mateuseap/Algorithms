# Bubble Sort Algorithm
#
# This algorithm sorts an array by repeatedly swapping adjacent elements if they are in the wrong order.
#
# Parameters:
# - array: The array to be sorted.
#
# Returns:
# - The sorted array.

def bubble_sort(array)
  n = array.size
  loop do
    swapped = false

    (n-1).times do |i|
      if array[i] > array[i+1]
        array[i], array[i+1] = array[i+1], array[i]
        swapped = true
      end
    end

    break if not swapped
  end

  array
end

def test_bubble_sort
  array = [64, 34, 25, 12, 22, 11, 90]
  sorted_array = bubble_sort(array)
  puts "Sorted array: #{sorted_array}"
end

test_bubble_sort
