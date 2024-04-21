

def ToBinary(t_input):
    temp = []
    u_input = int(t_input)
    while True:
        temp.append(u_input%2)
        u_input//=2
        if u_input == 0:
            break
    temp.reverse()

    binary_form = ''

    for iteration in temp:
        binary_form +=str(iteration)


    print(binary_form)

def FromBinary(t_input):
    correction = 0
    binary = ''
    try:
        for iteration in t_input:
            if iteration != '1' or iteration !='0':
                correction = 1
                raise ValueError

    except ValueError:
        while True:
            print("Please input your valye in binary: ")
            binary = input("Input binary to be converted: ")
            for iteration in binary:
                if iteration != '1' or iteration !='0':
                    continue
                
            break
    num0_length = len(t_input)
    num1_length = len(binary)
    temp = 0
    sum = 0

    if correction == 0:
        for num in t_input:
            num0_length-=1
            temp = int(num) * (2**num0_length)
            sum +=temp

    elif correction == 1:
        for num in binary:
            num1_length-=1
            temp = int(num) * (2**num1_length)
            sum +=temp

    print(sum)

            
user_input = input("Would you like to converter to binary(1) or from binary?(0) ")
if user_input == '1':
    prompt = input("Input the number you'd like to convert to binary: ")
    ToBinary(prompt)

elif user_input == '0':
    prompt = ("Input the number you'd like to convert from binary: ")
    FromBinary(prompt)
