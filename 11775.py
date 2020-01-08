"""
문제에서 주어진 식을 전개하면 ax + b 꼴이 나오게 된다.
a와 b를 구하기 위해서 x에 0과 1을 대입하면
x = 0 : b
x = 1 : a + b
따라서 이와 같은 방법으로 a와 b를 구할 수 있다
또한 x가 [0:M) 내에 있음은 자명하므로,
반복문을 통해 모든 x를 ax + b에 대입해보면 풀 수 있다.
식이 문자열로 주어지기 때문에 c++로 어떻게 구현을 해야하나 막막했는데,
파이썬의 내장함수에 갓갓함수인 eval(expression)이라는 함수가 있었다.
만약 eval("5 + 5")를 입력하면 10이 나오는 마법같은 내장함수이다..
이를 통해 a와 b를 쉽게 구할 수 있었다
"""

from sys import stdin

s = stdin.readline()
P, M = map(int, input().split())

x = 1
a = eval(s)
x = 0
b = eval(s)
a -= b

for i in range(M):
    if (a * i + b) % M == P:
        print(i)
        break 