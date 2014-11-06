/*
 * test_inventory.cpp
 *
 *  Created on: Nov 5, 2014
 *
 */

#include "gtest/gtest.h"
#include "Inventory.h"
#include "Item.h"
#include "IWeapon.h"
#include "IPotion.h"
#include "IBuff.h"

class test_inventory: public ::testing::Test {
protected:
	Inventory a;
	IWeapon w1(1,"sword","basic sword",10);
	IWeapon w2(2,"mace","mace",20);
	IWeapon w3(3,"ax","basic ax",30);

	IPotion p1(4,"p1","heals 10 hp",10);
	IPotion p2(5,"p2","heals 20 hp",20);
	IPotion p3(6,"p3","heals 30 hp",30);

	IBuff b1(7,"red","mod 1.1",1.1);
	IBuff b2(8,"green","mod 1.2",1.2);
	IBuff b3(9,"blue","mod 1.3",1.3);
};

TEST_F(test_inventory, add_IWeapon){
	EXPECT_TRUE(a.add_IWeapon(w1));
	EXPECT_FALSE(a.add_IWeapon(p1));
	EXPECT_FALSE(a.add_IWeapon(b1));

	map<int,Weap> testmap1 = a.get_invIWeapon();
	EXPECT_EQ(testmap1.size(),1);
}

TEST_F(test_inventory, add_IPotion){
	EXPECT_FALSE(a.add_IPotion(w1));
	EXPECT_TRUE(a.add_IPotion(p1));
	EXPECT_FALSE(a.add_IPotion(b1));

	map<int,int> testmap2 = a.get_invIPotion();
	EXPECT_EQ(testmap2.size(),1);
}

TEST_F(test_inventory, add_IBuff){
	EXPECT_FALSE(a.add_IBuff(w1));
	EXPECT_FALSE(a.add_IBuff(p1));
	EXPECT_TRUE(a.add_IBuff(b1));

	map<int,int> testmap3 = a.get_invIBuff();
	EXPECT_EQ(testmap3.size(),1);
}

TEST_F(test_inventory, remove_IWeapon){
	a.add_IWeapon(w1);
	map<int,Weap> testmap1 = a.get_invIWeapon();
	EXPECT_EQ(testmap1.size(),1);
	a.remove_IWeapon(w1);
	EXPECT_EQ(testmap1.size(),0);
}

TEST_F(test_inventory, remove_IPotion){
	a.add_IPotion(p1);
	map<int,int> testmap2 = a.get_invIPotion();
	EXPECT_EQ(testmap2.size(),1);
	a.remove_IPotion(p1);
	EXPECT_EQ(testmap2.size(),0);
}

TEST_F(test_inventory, remove_IBuff){
	a.add_IBuff(b1);
	map<int,int> testmap3 = a.get_invIBuff();
	EXPECT_EQ(testmap3.size(),1);
	a.remove_IBuff(b1);
	EXPECT_EQ(testmap3.size(),0);
}

TEST_F(test_inventory,equip_IWeapon){


}

TEST_F(test_inventory,unequip_IWeapon){


}
