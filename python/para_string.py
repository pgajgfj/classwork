
import lorem

# for i in range(1000000):
#     print(i, " --> ", chr(i),end="\t")
#     if i % 10 == 0:
#         print("")

# line = "Lorem ipsum dolor."
# print(id(line), line)
# line +='!!!!!!'
# print(line[3])
# print(len(line))
# print(line[3:len(line)])
# print(line[-10:-2])

# n1 = 2
# n2 = 5
# # 2+ 5 = 7
# example = '{} + {} = {}'.format(n1, n2 ,n1+n2)
# print(example)
# name = 'Perto'
# age = 22
# example = '{0} lorem {0} impusm {1}'.format(name, age)
# print(example)

# line_1 = 'Lorem ipsum'
# line_2 = "I love python \n" 
# line_3 = '''I   
#                 Love
#                         Python \n'''
# line_4 = '\\n - Enter'
# print(line_1, line_2, line_3 , line_4)

# print(r'\n - Enter')



digits = '52523535523'
letters = 'gdsgeqwfgsgawqfd'
line = 'Lorem ipsum dolor sit amet'
ditLetter ='fsdaf3424fsad23fsd'
word = 'Apple'
word2 = 'BANANA'
# print('===================isalnum()========================')
# print('\t', digits , ' ----> ', digits.isalnum())

# print('\t', letters, ' ----> ', letters.isalnum())

# print('\t', line , ' ----> ', line.isalnum())

# print('\t', ditLetter , ' ----> ', ditLetter.isalnum())

# print('\t', word, ' ----> ', word.isalnum())

# print('\t', word2 , ' ----> ', word2.isalnum())
# print('===================================================\n\n')

# print('===================isalpha()========================')
# print('\t', digits , ' ----> ', digits.isalpha())

# print('\t', letters, ' ----> ', letters.isalpha())

# print('\t', line , ' ----> ', line.isalpha())

# print('\t', ditLetter , ' ----> ', ditLetter.isalpha())

# print('\t', word, ' ----> ', word.isalpha())

# print('\t', word2 , ' ----> ', word2.isalpha())
# print('===================================================\n\n')

# print('===================isdigit()========================')
# print('\t', digits , ' ----> ', digits.isdigit())

# print('\t', letters, ' ----> ', letters.isdigit())

# print('\t', line , ' ----> ', line.isdigit())

# print('\t', ditLetter , ' ----> ', ditLetter.isdigit())

# print('\t', word, ' ----> ', word.isdigit())

# print('\t', word2 , ' ----> ', word2.isdigit())
# print('===================================================\n\n')

# print('===================islower()========================')
# print('\t', digits , ' ----> ', digits.islower())

# print('\t', letters, ' ----> ', letters.islower())

# print('\t', line , ' ----> ', line.islower())

# print('\t', ditLetter , ' ----> ', ditLetter.islower())

# print('\t', word, ' ----> ', word.islower())

# print('\t', word2 , ' ----> ', word2.islower())
# print('===================================================\n\n')

# print('===================isupper()========================')
# print('\t', digits , ' ----> ', digits.isupper())

# print('\t', letters, ' ----> ', letters.isupper())

# print('\t', line , ' ----> ', line.isupper())

# print('\t', ditLetter , ' ----> ', ditLetter.isupper())

# print('\t', word, ' ----> ', word.isupper())

# print('\t', word2 , ' ----> ', word2.isupper())
# print('===================================================\n\n')
# print('===================istitle()========================')
# print('\t', digits , ' ----> ', digits.istitle())

# print('\t', letters, ' ----> ', letters.istitle())

# print('\t', line , ' ----> ', line.istitle())

# print('\t', ditLetter , ' ----> ', ditLetter.istitle())

# print('\t', word, ' ----> ', word.istitle())

# print('\t', word2 , ' ----> ', word2.istitle())
# print('===================================================\n\n')

# print('===================isspace()========================')
# print('\t', digits , ' ----> ', digits.isspace())

# print('\t', letters, ' ----> ', letters.isspace())

# print('\t', line , ' ----> ', line.isspace())

# print('\t', ditLetter , ' ----> ', ditLetter.isspace())

# print('\t', word, ' ----> ', word.isspace())

# print('\t', word2 , ' ----> ', word2.isspace())
# print('===================================================\n\n')

# print('===================lower()========================')
# print('\t', digits , ' ----> ', digits.lower())

# print('\t', letters, ' ----> ', letters.lower())

# print('\t', line , ' ----> ', line.lower())

# print('\t', ditLetter , ' ----> ', ditLetter.lower())

# print('\t', word, ' ----> ', word.lower())

# print('\t', word2 , ' ----> ', word2.lower())
# print('===================================================\n\n')

# print('===================upper()========================')
# print('\t', digits , ' ----> ', digits.upper())

# print('\t', letters, ' ----> ', letters.upper())

# print('\t', line , ' ----> ', line.upper())

# print('\t', ditLetter , ' ----> ', ditLetter.upper())

# print('\t', word, ' ----> ', word.upper())

# print('\t', word2 , ' ----> ', word2.upper())

# print('===================================================\n\n')
# print('===================capitalize()========================')
# print('\t', digits , ' ----> ', digits.capitalize())

# print('\t', letters, ' ----> ', letters.capitalize())

# print('\t', line , ' ----> ', line.capitalize())

# print('\t', ditLetter , ' ----> ', ditLetter.capitalize())

# print('\t', word, ' ----> ', word.capitalize())
# print('\t', word2 , ' ----> ', word2.capitalize())

# print('===================================================\n\n')

# #.tiitle -vse s velikoy
# #swapcase - mala v veliky velika v malu



line +=" ipsum sit dolor ipsum"

# print('===================find()========================')

# print('\n\t', line , ' ----> ', line.index('ippsum'), '\n')
# # print('\n\t', line , ' ----> ', line.find('ipsum',7), '\n')
# # print('\n\t', line , ' ----> ', line.find('ipsum',28), '\n')
# # print('\n\t', line , ' ----> ', line.find('ipsum',44), '\n')

# # index = -1
# # while True:
# #     index = line.find('ipsum',index + 1)
# #     print('\n\t', line , ' ----> ', index, '\n')
# #     if index == -1:
# #         break

# print('===================================================\n\n')


# print('===================find()========================')
# print('\n\t', line , ' ----> ', line.count('ipsum'), '\n')
# print('===================================================\n\n')


numbers = '123'
line_1= '234'
line_2 = 'Lorem 21 Hello'
numbersF = 4.23569
# print("txt{1:2f}".format(numbersF))

import re
# print(re.search(r'1', numbers))
# print(re.search(r'1', line_1))
# print(re.search(r'1', line_2))

# print()
# print(numbers, ' --> ',  re.search(r'[12]', numbers))
# print(line_1,' --> ', re.search(r'[123]', line_1))
# print(line_2, ' --> ', re.search(r'[12]', line_2))
# print()
# print(numbers, ' --> ',  re.search(r'[0-4]', numbers))
# print(line_1,' --> ', re.search(r'[2-4]', line_1))
# print(line_2, ' --> ', re.search(r'[1-3]', line_2))

# match = re.search(r'[12]', numbers)
# print(type(match))



print(line_2, ' --> ', re.findall(r'\w+', line_2))
print(line, ' --> ', re.sub(r'[^m]{5}','blue', line))

print(line, ' --> ', line.replace('ipsum' , 'test'))


