// �������ݹ�ģ�ܴ���˵ò����ַ������д��� 
// ����Ҫ������������һ�ǳ˷��������ڶ����б���

#include <iostream>
#include <string>
using namespace std; 

// ���ܣ�ʵ����string�洢�����ֵĳ˷����� 
// �����б�ԭ�ַ���s���˷�����product 
// ����ֵ��ԭ�ַ������˷������õ����ַ��� 
string Multiplication(string s, unsigned int product) {
	int len = s.length();
	int count = 0, temp = 0; // count��¼Ӧ������һλ������temp��¼��λ���ֽ��г˷������õ��Ľ�� 
	for (int index = len - 1; index >= 0; index--) { // �����λ�����λ 
		temp = (s[index] - '0') * product + count;
		count = temp / 10;
		temp = temp % 10;
		s[index] = temp + '0';
	}
	
	// ����������λ����9��˵������λ�����ӣ���ô����һ��ȫΪ0���ҳ���Ϊԭ������+1���ַ���
	// ��ô����Ϊ�˷����б��������ж� 
	if (s[0] > '9') {
		string result;
		result.resize(len + 1);
		for (int index = 0; index <= len; index++) {
			result[index] = '0';
		}
		return result;
	}
	else return s;
}


// ���ܣ��ж��Ƿ�����Ƿ�Ϊѭ����
// �����б������˷�����õ����ַ���temp��ԭ�ַ���s��ԭ�ַ�������len 
// ����ֵ�����Ϊѭ����������true�����򷵻�false 
bool Judge(string& temp, const string s, const unsigned int len) {
	if (temp.length() != len) return false; // ע������ַ��������ȱ仯�ˣ���ôһ������ѭ����
	
	// ��temp�����һλŲ����һλ������ѭ�����Ķ��� 
	temp.insert(0, 1, temp[len - 1]);  temp.erase(len);	
	  
	char target = temp[0]; // �ӵ�һλ���бȶ� 
	size_t pos = 0;
	// ���ǵ�target�������ַ����е�ĳ�ظ��ַ��������s��Ӧ��Ӧ���ֿ��ܵ��ַ�������  
	while (pos < s.npos) {
		// �ĵã�size_t��C�ж����long long unsigned int���� 
	    // ���Ҫ��������һ��ý����������͵�ǿ��ת������Ȼ�����׷���������� 
	    // ���Ǽ�ʹ������ǿ��ת�������м��ʷ�����ѧ������˲���find()�ұ�s��target�ַ������п���λ��
		pos = s.find(target, pos); 
		for (unsigned int index = 0; index < len; index++, pos++) {
			if (pos == len)  pos -= len;
			if (temp[index] != s[pos]) break;
			if (index == len - 1) return true; // ֻҪ��һ�����ϵ��ַ������м��� 
		}
	}
	
	return false; // ��������ַ������ж���������������ô����false 
}

int main() {
	string s;  cin >> s;  
	unsigned int len = s.length();
	bool result = true;
	
	string temp = " "; // ����ԭ���ַ������˷������Ľ�� 
	for (unsigned int product = 2; product <= len; product++) {
		temp = Multiplication(s, product);
		result = Judge(temp, s, len);  
		cout << endl;
		if (!result) {
			cout << "No";
			return 0;
		} 
	}
	
	cout << "Yes";
	return 0;
} 
