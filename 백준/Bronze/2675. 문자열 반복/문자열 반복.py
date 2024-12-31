TestCase = int(input())
for _ in range(TestCase):
    repeat, target = input().split()
    result_string = ""
    for i in range(len(target)):
        result_string += target[i]*int(repeat)
    print(result_string)