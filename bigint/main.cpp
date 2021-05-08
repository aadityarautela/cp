#include <bits/stdc++.h>
using namespace std;

bool is_zero(string num)
{
    if (num[0] == '0')
        return true;
    else
        return false;
}

// sum, carry
pair<string, string> add_single(string a, string b, string carry)
{
    return make_pair(to_string((stoi(a) + stoi(b) + stoi(carry)) % 10), to_string((stoi(a) + stoi(b) + stoi(carry)) / 10));
}

string add(string a, string b)
{

    if (is_zero(a))
    {
        return b;
    }
    else if (is_zero(b))
    {
        return a;
    }
    else
    {
        string carry = "0";
        int size_diff = a.size() - b.size();
        int abs_size_diff = abs(size_diff);
        if (size_diff > 0)
        { // digits of a > digits of b
            b.insert(0, abs_size_diff, '0');
        }
        else if (size_diff < 0)
        { // digits of a < digits of b
            a.insert(0, abs_size_diff, '0');
        }
        int net_size = a.size();
        string result = "";
        for (int i = net_size - 1; i >= 0; i--)
        {
            string sum;
            pair<string, string> sum_and_carry = add_single(a.substr(i, 1), b.substr(i, 1), carry);
            sum = sum_and_carry.first;
            carry = sum_and_carry.second;
            result.push_back(sum[0]);
        }
        if (carry != "0")
            result.push_back(carry[0]);
        reverse(result.begin(), result.end());
        return result;
    }
}

string multiply(string a, string b)
{
    if (is_zero(a) || is_zero(b))
    {
        return "0";
    }
    else
    {
        vector<string> mul_rows;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            int shift_amt = b.size() - i - 1;
            string partial_sum = "0";
            for (int j = 0; j < stoi(b.substr(i, 1)); j++)
            {
                partial_sum = add(partial_sum, a);
            }

            partial_sum.append(shift_amt, '0');
            mul_rows.push_back(partial_sum);
        }
        string result = mul_rows[0];
        for (int i = 1; i < mul_rows.size(); i++)
        {
            result = add(result, mul_rows[i]);
        }
        return result;
    }
}

string factorial(string num) {
    int loop_limit = stol(num);
    string fact = "1";
    for(int i=1;i<=loop_limit; i++) {
        fact = multiply(fact, to_string(i));
    }
    return fact;
}

int main()
{
    string a;
    cin >> a;
    cout<<factorial(a)<<endl;
    return 0;
}