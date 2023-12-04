/*
* 5���� ī�� ������ �Է��ϸ� ��Ŀ�� ������ �˷��ִ� ���α׷��� �ۼ��Ͽ���.
* ī���� ���̴� �����̵�(S), ���̾Ƹ��(D), ��Ʈ(H), Ŭ�ι�(C) �� �����̸�, ī���� ���ڴ� 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A 13�����̴�.
* ���ĺ��� �׻� �빮�ڷ� �Է��Ѵٰ� �����Ѵ�.
* �� ī�� ������ �Ʒ��� ������ ����ü���� ����Ͽ� �����ϸ�, �Էµ� 5���� ī�� ������ ũ�Ⱑ 5�� ����ü �迭�� �����Ѵ�.
* �ݵ�� �� ���� Ȯ���� ���� 12���� �Լ��� �ۼ��ؾ� �Ѵ�.
*/

/*
* �������� ��� X
* ���õ� struct card ����ü�� ī�带 ����
* ���α׷��� �޴� 3���� ������ ��쿡�� ����
*/
#include <iostream>
#include "stdlib.h"

using namespace std;

typedef enum poker_genealogy
{
	ROYAL_STRAIGHT_FLUSH, BACK_STRAIGHT_FLUSH, STRAIGHT_FLUSH, 
	FOUR_CARD, FULL_HOUSE, FLUSH, 
	MOUNTAIN, BACK_STRAIGHT, STRAIGHT, 
	TRIPLE, TWO_PAIR, ONE_PAIR
}POKER_GENEALOGY;

POKER_GENEALOGY check_genealogy(class Card myCard[]);
bool royal_straight_flush(class Card myCard[]);
bool back_straight_flush(class Card myCard[]);
bool straight_flush(class Card myCard[]);
bool four_card(class Card myCard[]);
bool full_house(class Card myCard[]);
bool flush(class Card myCard[]);
bool mountain(class Card myCard[]);
bool back_straight(class Card myCard[]);
bool straight(class Card myCard[]);
bool triple(class Card myCard[]);
bool two_pair(class Card myCard[]);
bool one_pair(class Card myCard[]);

class Card
{
private:
	string shape;
	string number;
public:
	Card()
	{
		shape = "S";
		number = "A";
	}

	void setCard(string card_shape, string card_number)
	{
		this->setCardShape(card_shape);
		this->setCardNumber(card_number);
	}

	void setCardShape(string card_shape = "S") { shape = card_shape; };
	string getCardShape() { return shape; };

	void setCardNumber(string card_number = "A") { number = card_number; };
	string getCardNumber() { return number; };
};

int main()
{
	int chose_number;
	Card poker[5];
	
	while (true)
	{
		//ī�� 5�� �Է� �Ǵ� �������� �����ϱ�
		cout << "1. ���� �Է�\t2. ���� ����\t3. ����\n\n";
		cout << "��ȣ�� �Է��ϼ���: ";
		cin >> chose_number;

		if (chose_number == 1)
		{
			//ī�� 5�� �Է��ϱ�
			cout << "5���� ī�� ������ �Է��ϼ���." << endl;
			for (int i = 1; i < 6; i++)
			{
				string card_shape;
				string card_number;
				cout << i << "�� ī�� ���̿� ����: ";
				cin >> card_shape >> card_number;
				poker[i - 1].setCard(card_shape, card_number);
			}

			//������ ���ؼ� ��� ���
			string result;
			switch (check_genealogy(poker))
			{
			case ROYAL_STRAIGHT_FLUSH:
				result = "�ξ� ��Ʈ����Ʈ �÷���";
				break;
			case BACK_STRAIGHT_FLUSH:
				result = "�� ��Ʈ����Ʈ �÷���";
				break;
			case STRAIGHT_FLUSH:
				result = "��Ʈ����Ʈ �÷���";
				break;
			case FOUR_CARD:
				result = "��ī��";
				break;
			case FULL_HOUSE:
				result = "Ǯ�Ͽ콺";
				break;
			case FLUSH:
				result = "�÷���";
				break;
			case MOUNTAIN:
				result = "����ƾ";
				break;
			case BACK_STRAIGHT:
				result = "�齺Ʈ����Ʈ";
				break;
			case STRAIGHT:
				result = "��Ʈ����Ʈ";
				break;
			case TRIPLE:
				result = "Ʈ����";
				break;
			case TWO_PAIR:
				result = "�� ���";
				break;
			case ONE_PAIR:
				result = "�� ���";
				break;
			}
			cout << "���: " << result;
		}
		else if (chose_number == 2)
		{
			cout << "1. royal_straight_flush\t2. back_straight_flush\n"
				<< "3. straight_flush\t\t4. four_card\n"
				<< "5. full_house\t\t6. flush"
				<< "7. mountain\t\t8. back_straight\n"
				<< "9. straight\t\t\t10. triple\n"
				<< "11. two_pair\t\t\t12. one_pair\n\n";
		}
		else
		{
			cout << "�ٽ� �Է����ּ���" << endl;
		}
	}
	return 0;
}

POKER_GENEALOGY check_genealogy(class Card myCard[])
{
	if (royal_straight_flush(myCard))
		return ROYAL_STRAIGHT_FLUSH;
	else if (back_straight_flush(myCard))
		return BACK_STRAIGHT_FLUSH;
	else if (straight_flush(myCard))
		return STRAIGHT_FLUSH;
	else if (four_card(myCard))
		return FOUR_CARD;
	else if (full_house(myCard))
		return FULL_HOUSE;
	else if (flush(myCard))
		return FLUSH;
	else if (mountain(myCard))
		return MOUNTAIN;
	else if (back_straight(myCard))
		return BACK_STRAIGHT;
	else if (straight(myCard))
		return STRAIGHT;
	else if (triple(myCard))
		return TRIPLE;
	else if (two_pair(myCard))
		return TWO_PAIR;
	else if (one_pair(myCard))
		return ONE_PAIR;
};

bool royal_straight_flush(class Card myCard[])
{
	//���ڰ� �� �ִ��� Ȯ��
	int allNumberExist = 0;
	for (int i = 0; i < 5; i++)
	{
		if (myCard[i].getCardNumber() == "10" ||
			myCard[i].getCardNumber() == "J" ||
			myCard[i].getCardNumber() == "Q" ||
			myCard[i].getCardNumber() == "K" ||
			myCard[i].getCardNumber() == "A")
			allNumberExist++;
	}
	if (myCard[0].getCardShape() == myCard[1].getCardShape()
		&& myCard[1].getCardShape() == myCard[2].getCardShape()
		&& myCard[2].getCardShape() == myCard[3].getCardShape()
		&& myCard[3].getCardShape() == myCard[4].getCardShape()
		&& myCard[4].getCardShape() == myCard[5].getCardShape())
		if (allNumberExist == 5)
			return true;
	else
		return false;	
};