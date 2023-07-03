# a = int(input("Enter nuber A -->"))
# b = int(input("Enter nuber B -->"))
# i= 1
# while a<b:
    
    
# a = int(input("Enter nuber A -->"))
# b = int(input("Enter nuber B -->"))
# num = a
# while num < b:
#     div = 0
#     i =1
#     while i <= num:
#         if num % i == 0:
#             div +=1
#         i+=1
#     print("Дільники для числа", num, "—", end=" ")
#     i =1
#     while i <= num:
#         if num % i == 0:
#             print(i ,end=" ")
#         i+=1
#     print()
#     num +=1
# #2
# a = 3
# b= 1000
# while  a<=b:
#     prime = True
#     div  = 2
#     while div< a:
#         if a % div == 0:
#             prime = False
#             break
#         div +=1
#     if prime== True:
#             print(a)
#     a+=1    
# #3
# code = 100
# c = 0
# while code  <1000:
#     code1 = code // 100
#     code2 = (code // 10) %10
#     code3 = code %10
#     if code1 !=code2 and code2!= code3 and code3!=code1:
#         print([code1, code2,code3])
#         c +=1
#     code +=1
# print("Кількість комбінацій -->", c)
# print("Час для відкритя в гіршому випадку -->", c *3,"секунди")
# #ostane
# n = 7
# start_space= 0
# space = n//2 -1
# flag = True

# for i in range(n):
#     if i == n//2:
#         print("*"*n)
#         flag == False
#         start_space-=1
#         space+=1
#         continue   
#     print(" "*start_space ,"*", " " * space, "*", " " * space, "*",sep="")
#     if i<n//2 and space ==  0:
#         continue
#     if flag:
#         start_space +=1
#         space -=1
#     else:
#         start_space -=1
#         space +=1


