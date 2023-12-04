/*
* 5장의 카드 정보를 입력하면 포커의 족보를 알려주는 프로그램을 작성하여라.
* 카드의 무늬는 스페이드(S), 다이아몬드(D), 하트(H), 클로버(C) 네 종류이며, 카드의 숫자는 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A 13가지이다.
* 알파벳은 항상 대문자로 입력한다고 가정한다.
* 각 카드 정보는 아래에 제시한 구조체형을 사용하여 관리하며, 입력된 5장의 카드 정보는 크기가 5인 구조체 배열에 저장한다.
* 반드시 각 족보 확인을 위한 12개의 함수를 작성해야 한다.
*/

/*
* 전역변수 사용 X
* 제시된 struct card 구조체로 카드를 관리
* 프로그램은 메뉴 3번을 선택한 경우에만 종료
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
		//카드 5개 입력 또는 랜덤생성 선택하기
		cout << "1. 직접 입력\t2. 랜덤 생성\t3. 종료\n\n";
		cout << "번호를 입력하세요: ";
		cin >> chose_number;

		if (chose_number == 1)
		{
			//카드 5개 입력하기
			cout << "5개의 카드 정보를 입력하세요." << endl;
			for (int i = 1; i < 6; i++)
			{
				string card_shape;
				string card_number;
				cout << i << "번 카드 무늬와 숫자: ";
				cin >> card_shape >> card_number;
				poker[i - 1].setCard(card_shape, card_number);
			}

			//족보랑 비교해서 결과 출력
			string result;
			switch (check_genealogy(poker))
			{
			case ROYAL_STRAIGHT_FLUSH:
				result = "로얄 스트레이트 플러쉬";
				break;
			case BACK_STRAIGHT_FLUSH:
				result = "백 스트레이트 플러쉬";
				break;
			case STRAIGHT_FLUSH:
				result = "스트레이트 플러쉬";
				break;
			case FOUR_CARD:
				result = "포카드";
				break;
			case FULL_HOUSE:
				result = "풀하우스";
				break;
			case FLUSH:
				result = "플러쉬";
				break;
			case MOUNTAIN:
				result = "마운틴";
				break;
			case BACK_STRAIGHT:
				result = "백스트레이트";
				break;
			case STRAIGHT:
				result = "스트레이트";
				break;
			case TRIPLE:
				result = "트리플";
				break;
			case TWO_PAIR:
				result = "투 페어";
				break;
			case ONE_PAIR:
				result = "원 페어";
				break;
			}
			cout << "결과: " << result;
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
			cout << "다시 입력해주세요" << endl;
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
	//숫자가 다 있는지 확인
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