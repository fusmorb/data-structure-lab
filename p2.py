input = ")))()"

def problem2(input):
    left_needed = 0
    right_needed = 0

    for char in input:
        if char == '(':
            right_needed += 1
        elif char == ')':
            if right_needed > 0:
                right_needed -= 1
            else:
                left_needed += 1

    return left_needed + right_needed

result = problem2(input)

assert result == 3
print("정답입니다.")
