#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <chrono>
#include <ctime>
#include <algorithm>

#define K 100
#define LN 25
#define N 20

using namespace std;

vector<int> ln;
typedef pair < int, int > vstore;
int cond_check = 0;
stack<vstore> sstore;

void reheap_insert(int start, int p_i, int p_o, vector<int>& values)
{
	int lc_o, rc_o, lc_i, rc_i;
	lc_o = p_o - 1;
	rc_o = p_o - 2;

	if (lc_o >= 0 && rc_o >= 0)
	{
		lc_i = p_i - ln[rc_o] - 1;
		rc_i = p_i - 1;

		while (p_i != start && p_i != start + 1)
		{
			//if (values[rc_i] > values[lc_i])
			//{
			//	if (values[rc_i] > values[p_i])
			//	{
			//		int temp = values[p_i];
			//		values[p_i] = values[rc_i];
			//		values[rc_i] = temp;
			//		if (start + 1 != rc_i)
			//			reheap_insert(lc_i + 1, rc_i, rc_o, values);
			//		else
			//			break;
			//	}
			//}
			//else if (values[lc_i] > values[p_i])
			//{
			//	int temp = values[p_i];
			//	values[p_i] = values[lc_i];
			//	values[lc_i] = temp;
			//	if (start != lc_i)
			//		reheap_insert(start, lc_i, lc_o, values);
			//	else
			//		break;
			//}

			if (values[lc_i] > values[rc_i])
			{
				if (values[lc_i] > values[p_i])
				{
					int temp = values[p_i];
					values[p_i] = values[lc_i];
					values[lc_i] = temp;
					if (start != lc_i)
						reheap_insert(start, lc_i, lc_o, values);
				}
			}
			else if (values[rc_i] > values[p_i])
			{

				int temp = values[p_i];
				values[p_i] = values[rc_i];
				values[rc_i] = temp;
				if (start + 1 != rc_i)
					reheap_insert(lc_i + 1, rc_i, rc_o, values);
			}
			break;
		}
	}
}

void sort_root(vector<int>& v)
{
	vector<vstore> values, temp;
	vector<vstore>::iterator it;
	vstore pop;
	while (sstore.size() != 0)
	{
		pop = sstore.top();
		temp.push_back(pop);
		sstore.pop();
	}
	while (temp.size() != 0)
	{
		values.push_back(temp[temp.size() - 1]);
		temp.pop_back();
	}
	size_t least = 0;
	for (int i = 0; i < values.size() - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < values.size(); ++j)
		{
			if (v[values[j].second] < v[values[least].second])
			{
				cond_check = 1;
				least = j;
			}
		}
		int idx = values[least].second;
		int temp = v[idx];
		int idx1 = values[i].second;
		int temp1 = v[idx1];
		v[values[i].second] = temp;
		v[values[least].second] = temp1;
	}
	for (int i = 0; i < values.size(); i++)
	{
		sstore.push(values[i]);
	}
}


void insert(vector<int>& value)
{
	int len = value.size();
	int count = 0, cond = 2;

	//default
	if (value.size() == 0 || value.size() == 1)
	{
		return;
	}

	while (count < len)
	{
		int lco = -1, rco = -1, lci = -1, rci = -1;
		vstore pop1, pop2;
		pop1.first = -1;
		pop1.second = -1;
		pop2.first = -1;
		pop2.second = -1;

		//0.0
		if (sstore.size() != 0 && lco == -1)
		{
			pop1 = sstore.top(); sstore.pop();
			if (sstore.size() != 0)
			{
				pop2 = sstore.top(); sstore.pop();
				if (abs(pop1.first - pop2.first) == 1)
				{
					rco = pop1.first;
					rci = pop1.second;

					lco = pop2.first;
					lci = pop2.second;
				}
				else
				{
					sstore.push(pop2);
					lco = pop1.first;
					lci = pop1.second;
				}
			}
			else
			{
				lco = pop1.first;
				lci = pop1.second;
			}
		}
		//1.1  1.2
		if (lco >= 0 && rco >= 0)
		{
			if ((lco - rco) == 1)
			{
				reheap_insert((count + 1) - ln[lco + 1], count, lco + 1, value);


				//END
				vstore temp(++lco, count);
				sstore.push(temp);
				lco = -1; rco = -1;
				lci = -1; rci = -1;
				cond = 1;
			}
			//1.3
			else
			{
				sstore.push(make_pair(lco, lci));
				lco = rco; lci = rci;
				rco = -1; rci = -1;
				cond = 2;
			}
		}
		//2.1
		else if (cond == 2)
		{
			if (lco == -1)
			{
				lco = 1;
				lci = count;
				sstore.push(make_pair(lco, lci));
			}
			else
			{
				if (lco != 1)
				{
					rco = 1;
				}
				else
				{
					rco = 0;
				}
				rci = count;

				sstore.push(make_pair(lco, lci));
				sstore.push(make_pair(rco, rci));
			}
		}

		//3.0
		do
		{
			cond_check = 0;
			vector<vstore> pairs;
			sort_root(value); // yes = cond_test = 1;
			if (cond_check == 1)
			{
				while (sstore.size() != 0)
				{
					pairs.push_back(sstore.top());
					sstore.pop();
				}
				for (int i = 1; i < pairs.size(); i++)
				{
					reheap_insert((pairs[i].second + 1) - ln[pairs[i].first], pairs[i].second, pairs[i].first, value);
				}

				for (int i = pairs.size() - 1; i >= 0; i--)
				{
					sstore.push(pairs[i]);
				}
			}

		} while (cond_check == 1);
		cond = 2;
		count++;
	}
}

void dequeue(vector<int>& value)
{
	size_t count = value.size();
	vector<vstore> store;
	vstore pop1;
	int lc_o, rc_o, lc_i, rc_i;

	while (count != 0)
	{
		pop1 = sstore.top();
		sstore.pop();
		if (pop1.first == 1 || pop1.first == 0)
		{
			count--;
		}
		else
		{
			lc_o = pop1.first - 1;
			rc_o = pop1.first - 2;

			lc_i = pop1.second - ln[rc_o] - 1;
			rc_i = pop1.second - 1;

			sstore.push(make_pair(lc_o, lc_i));
			sstore.push(make_pair(rc_o, rc_i));

			do
			{
				cond_check = 0;
				vector<vstore> pairs;
				sort_root(value); // yes = cond_test = 1;
				if (cond_check == 1)
				{
					while (sstore.size() != 0)
					{
						pairs.push_back(sstore.top());
						sstore.pop();
					}
					for (int i = 1; i < pairs.size(); i++)
					{
						reheap_insert((pairs[i].second + 1) - ln[pairs[i].first], pairs[i].second, pairs[i].first, value);
					}

					for (int i = pairs.size() - 1; i >= 0; i--)
					{
						sstore.push(pairs[i]);
					}
				}

			} while (cond_check == 1);
			count--;
		}
	}
}


int main()
{
	srand(time(0));

	double dur_arr[K + 10];
	int ln1 = 1, ln2 = 1, ln3;

	// Realizing Leonardo numbers
	ln.push_back(ln1);
	ln.push_back(ln2);
	for (int i = 0; i < LN; ++i) {
		ln.push_back(ln1 + ln2 + 1);
		ln2 = ln1 + ln2;
		ln1 = ln2;
	}

	vector<int> values;
	vector<int> values_copy;

	for (int i = 0; i < K; ++i) {

		for (int i = 0; i < N; ++i)
			values.push_back(rand() % 100 + 1);

		for (int i = 0; i < N; ++i)
			values_copy.push_back(values[i]);

		auto start = chrono::high_resolution_clock::now();

		insert(values);
		dequeue(values);

		auto end = chrono::high_resolution_clock::now();

		chrono::duration<double> duration = end - start;
		dur_arr[i] = duration.count();
		values.clear();
		for (int i = 0; i < N; ++i)
			values.push_back(values_copy[i]);
	}
	cout << "Default array:" << endl;
	for (int i = 0; i < N; ++i)
		cout << values_copy[i] << endl;
	insert(values);
	dequeue(values);
	cout << "Sorted array: " << endl;
	for (int i = 0; i < N; i++)
		cout << values[i]<< endl;
	for (int i = 0; i < K; ++i)
		cout << "Duration " << i + 1 << " = " << dur_arr[i] << "s" << endl;
	double avg_dur=0;
	for (int i = 0; i < K; ++i) 
		if (dur_arr[i] > 0)avg_dur += dur_arr[i];
	sort(dur_arr, dur_arr + K);
	cout << "Average duration: " << avg_dur / (K - 40) << "s";
	return 0;
}