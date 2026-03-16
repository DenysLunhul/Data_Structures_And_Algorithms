cmake_minimum_required(VERSION 4.1)
project(data_structures_and_algorhitms)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_structures_and_algorhitms lectures_examples/permutations.cpp
        lectures_examples/add_1_binary.cpp
        lectures_examples/balanced_weigth.cpp
        lectures_examples/eratosphen_sieve.cpp
        algotester/Lab1/a1.cpp
        algotester/Lab1/a2.cpp
        algotester/Lab1/a3.cpp
        algotester/Lab1/a4.cpp
        algotester/Lab1/a5.cpp
        algotester/Lab1/b1.cpp
        algotester/Lab1/b2.cpp
        algotester/Lab1/b3.cpp
        sorting_algorithms/bubble.cpp
        sorting_algorithms/insertion.cpp
        sorting_algorithms/selection.cpp
        sorting_algorithms/merge.cpp
        sorting_algorithms/quick.cpp
        test.cpp
        lectures_examples/prefix_sum_1d.cpp
        lectures_examples/find_sum_in_array.cpp
        lectures_examples/most_segments.cpp
        lectures_examples/deputy_ties.cpp
        algotester/Lab2/a1.cpp
        algotester/Lab2/a2.cpp
        algotester/Lab2/a3.cpp
        algotester/Lab2/a4.cpp
        algotester/Lab2/a5.cpp
        algotester/Lab2/b1.cpp
        algotester/Lab2/b3.cpp
        algotester/Lab2/b2.cpp
        lectures_examples/stairs_combs.cpp
        lectures_examples/longest_increasing_subsequence.cpp
        lectures_examples/longest_common_part_in_words.cpp
        lectures_examples/cars_and_gas_stations.cpp
        lectures_examples/coridor_and_flowers.cpp
        lectures_examples/polygon_triangulation.cpp
        lectures_examples/2_planes_ternar_search.cpp
        lectures_examples/prefix_sum_with_element_replacement.cpp
        algotester/Lab3/a1.cpp
        algotester/Lab3/a2.cpp
        algotester/Lab3/a3.cpp
        algotester/Lab3/a4.cpp
        algotester/Lab3/a5.cpp
        algotester/Lab3/b1.cpp
        algotester/Lab3/b2.cpp
        algotester/Lab3/b3.cpp
        lectures_examples/segments_tree_max.cpp
        lectures_examples/segments_tree_sum.cpp
)
