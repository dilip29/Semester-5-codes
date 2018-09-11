//create a clas rational for performming arithmetic operation or fractional
//use integer variables to represent private date of class that can be numerator and denominator
//provide a constructor for initialising the objects . it should contain deault values in case no initialisation are provided shouls stroe the fraction in reduced forn eg 2/4 
//provide public member functions for following operators 
// 1.aditing  ration no.s 2. multipli  rational no.s 3. subtracting 4. divide  5. printing in form of a/b  6. printing in floating form 

//only logical correct operations



#include<iostream>
#include "rational_class.cpp"
#include<cmath>

using namespace std;

int gcd (int p ,int q)
{

    if (p==q )
        return p;

    else if (p*q==0)
        return 1;

    else if (p<q)
        return gcd(p,q-p);

    else
        return gcd(q,p-q);


}

int main() {

    int p1, q1, p2, q2;

    cout << "enter p1\n";
    cin >> p1;
    cout << "enter q1\n";
    cin >> q1;
    cout << "enter p2\n";
    cin >> p2;
    cout << "enter q2\n";
    cin >> q2;

    if (q1 * q2 == 0) {
        cout << "enter non zero deno" << endl;
        return 0;
    }


    Rational r1(p1, q1);
    Rational r2(p2, q2);

    Rational res, res_sum, res_sub, res_mul, res_div;

    res_sum = res.add(r1, r2);
    res_sub = res.sub(r1, r2);
    res_mul = res.mul(r1, r2);
    res_div = res.div(r1, r2);

    int m;
    m = gcd((res_sum.getnum()), (res_sum.getdeno()));
    cout << "the sum is :" << res_sum.getnum() / m << " /" << res_sum.getdeno() / m << endl;

//cout<<"the diff is :"<<res_sub.getnum()<< " /" <<res_sub.getdeno()<<endl;


    m = gcd(abs(res_sub.getnum()), abs(res_sub.getdeno()));
    cout << "the diff is :" << res_sub.getnum() / m << " /" << res_sub.getdeno() / m << endl;


    m = gcd(res_mul.getnum(), res_mul.getdeno());
    cout << "the mul is :" << res_mul.getnum() / m << " /" << res_mul.getdeno() / m << endl;

    if (res_div.getdeno() == 0) {
        cout << "zero division error" << endl;
        return 0;
    }

    m = gcd(res_div.getnum(), res_div.getdeno());
    cout << "the div is :" << res_div.getnum() / m << " /" << res_div.getdeno() / m << endl;
    return 0;


}