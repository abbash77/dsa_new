#include<iostream>
using namespace std;

int main(){
    /*odd and even
    num&1==1 odd
    num&1==0 even
    >> right shift
    << left shift
    ---------------------------------------------------------------
    To subtract two number 7-5
    we can write it as 7+(-5)
    to convert 5 to -5 . we have to take 2's compliment of 5 
    2's compliment of 5 is: 
    1.invert all the bits of the number, then add 1 to it.
    ----------------------------------------------------------------
    Swap two number
    a=5,b=7
    3-steps:
    a=a^b
    b=a^b
    a=a^b
    ----------------------------------------------------------------
    Bit Masking
    1.find ith bit
    2.set ith bit
    3.clear ith bit

    1.
    we have to find the 5th bit 
    1 0 0 '1' 1 0 1 0 1
    8 7 6  5  4 3 2 1 0
    so using previous method just like in even and odd, we can AND above number to
    0 0 0  1  0 0 0 0 0 -- mask, mask kaise milega 1 ko left shift krdo 5 times
    and if the result is non -zero then the 5th bit is 1
    and if the result is zero then the 5th bit is 0
    2.
    set 3rd bit
    take above number
    mask bnao same walaa
    0 0 0  0  0 1 0 0 0
    phir dono ko OR krdo
    3.
    4th bit ko clear krna h
    1 0 0 1 1 0 1 0 1
    hme mask bnana hoga
    1 1 1 1 0 1 1 1 1
    agar in dono ko AND krde to kaam hojayega
    but wo mask bnaye kaise--> 1 ko shift kro 4 times phir (~)complement krdo usko
    ~(1<<4)
    ---------------------------------------------------------------
    question:
    find number of bits to change to convert a to b
    a-> 10110
    b-> 11011
    mujhe pta hh jo bits same h usko nhi change krna hh
    to 3 bits alag hh unko change krna hh bas
    so answer is 3, but how we will solve this 
    to pahle to xor lgao taaki jaha jaha problem ho sab 1 hojaaye
    after xor -> 01101
    now we have to count number of ones in this number
    n->1101 

    first method-> n ko right shift krte jao aur count krte jao kitni baar 1 aaya
    yaha pe complexity hogi O(4)
    if n=13
    complexity is log(n)+1; log(13)+1==>>>>4
    but this is not optimised now we can use another method here:

    second method:
    (very imp)---> n&(n-1) yaha pe ye hota ki lease significant bit jo hh wo zero hojaati
    1101
    1100 cnt++
    1000 cnt++
    0000 cnt++
    cnt=3;
    here complexity will be O(3)-> where 3 is number of set bits

    --------------------------------------------------------------------

    XOR properties and questions
    1. n^n==0
    2. 0^n==n
    3. 5^4^3^5==4^3 , 5 aur 5 ek dusre ko cancel krdenge 

    q1. find the only non-repeating ele in an array where every ele repeat twice.
    [5,4,1,4,3,5,1]
    res=0;
    is res ko sabse xor krte jao
    res=0^5=5
    res=5^4
    res=5^4^1
    res=5^4^1^4-->5^1, 4 aur 4 ek dusre ko cancel krdenge
    res=5^1^3
    res=5^1^3^5===1^3
    res=1^3^1==3
    loop end, 3 is the answer

    q2. find the two non-repeating ele in an array where every ele repeat twice.
    [5,4,1,4,3,5,1,2]
    same pichle q ki tarah kre to finally 3^2 bachega 
    res=3^2=1
        a^b
    ab a or b ko alag kaise kre
    01
    a aur b ka last bit opposite hoga
    last bit one mtlb ki jo 2 number hone usme 1 even , 1 odd hoga
    (agar rightmost set bit 2nd number pe 1 aati ex. a^b==0100 to hum isko 2 group me 
    divide krte jisme 1 me 2nd bit zero rhe aur dusre me 1 rhe)
    upar waale array me last bit one waalo ko alag kro aur zero waalo ko alag
    (5,1,3,5,1) ^ (3^2) sab cut gye bas 2 bach gya
    ab 2 ko xor krdo result ke saaath
    (3^2)^2==> 3
    so 2 and 3 are the final answer

    q3. find the only non repeating element in an array where every other element 
    repeats thrice
    [2,2,1,5,1,1,2]
    32 bits ka 1 number bnalo jiski value 0 ho
    aur count krte jao ki kiss position pe kitni baar bit 1 horhi
    2->10
    2->10
    1->01
    5->101
    1->01
    1->01
    2->10
    32 bit ka array
    [0,0,0,0.........0,0,0,0] initially
    [0,0,0,0.........0,1,3,4]
    ab jo three ke multiple honge wo 3 baar aa chuke hh
    hme 3n+1 waala dhoondna hh
    [0,0,0,0.........0,1,0,1]---> and this is equal to 5,modulo 3 krdena
    another ques -> 3 times ki jagah k times hoga tab kya krenge 
    to tab sirf modulo k krdenge










    
    
    */



    return 0;
}