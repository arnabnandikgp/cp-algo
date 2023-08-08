def count_valid_sequences(n_tosses):
    end_with_H = 1
    end_with_T = 1

    for _ in range(2, n_tosses + 1):
        new_end_with_H = end_with_T
        new_end_with_T = end_with_H + end_with_T
        end_with_H = new_end_with_H
        end_with_T = new_end_with_T

    return end_with_H + end_with_T

total_outcomes = 2**10
valid_sequences = count_valid_sequences(10)
probability = valid_sequences / total_outcomes

print(f"Probability that 3 consecutive heads don't appear in 10 tosses: {probability:.6f}")
