import random

char_list = [chr(c) for c in range(48, 127)]
random.shuffle(char_list)

password = ""

for i in char_list:
    for j in char_list:
        for k in char_list:
            if ord(i)+ord(j)+ord(k) == 300:
                password = f'{random.choice(char_list)}@{i}{j}{k}'
                break
    if password:
        break

# Generate valid user passwords
print(password)

# Generate "admin exploited" passwords. Piping needed for non-printable chars
# padding = ''.join(random.sample(char_list, 11))
# print(f'{password}{padding}\0')
