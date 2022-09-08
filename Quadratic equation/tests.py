import random as rnd

f_data = open('data.txt', 'w')
f_answer = open('answers.txt', 'w')

for i in range(30):
    a = rnd.randint(-10, 10)
    b = rnd.randint(-10, 10)
    c = rnd.randint(-10, 10)

    f_data.write(str(a) + ' ' + str(b) + ' ' + str(c) + '\n')

    if a == 0 and b != 0:
        x_1 = -c / b
        x_1 = round(x_1, 3)
        f_answer.write("This is linear equation: x = " + str(x_1) + '\n')
        continue

    if a == 0 and b == 0 and c == 0:
        f_answer.write("Infinite number of roots\n")
        continue

    D = b * b - 4 * a * c
    if D < 0:
        f_answer.write("There is no roots\n")
        continue
    elif D == 0:
        x_1 = -b / 2 * a
        x_1 = round(x_1, 3)
        f_answer.write("One root exists: x = " + str(x_1) + '\n')
        continue
    else:
        x_1 = (-b + D ** 0.5) / 2 * a
        x_1 = round(x_1, 3)
        x_2 = (-b - D ** 0.5) / 2 * a
        x_2 = round(x_2, 3)
        f_answer.write("Two roots exist: x_1 = " + str(x_1) + "; x_2 = " + str(x_2) + '\n')
        continue

f_answer.close()
f_data.close()

