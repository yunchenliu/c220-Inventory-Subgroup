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
	Inventory a();
	IWeapon w1(1,"sword","basic sword",10);
	IWeapon w2(2,"mace","basic mace",20);
	IWeapon w3(3,"axe","basic axe",30);

	IPotion p1(4,"p1","heals 10 hp",10);
	IPotion p2(5,"p2","heals 20 hp",20);
	IPotion p3(6,"p3","heals 30 hp",30);

	IBuff b1(7,"red","Increases atk by 10%",1.1);
	IBuff b2(8,"green","Increases atk by 20%",1.2);
	IBuff b3(9,"blue","Increases atk by 10%",1.3);
};

TEST_F(test_inventory, add_IWeapon){
	EXPECT_TRUE(a.add_IWeapon(w1));
	EXPECT_FALSE(a.add_IWeapon(p1));
	EXPECT_FALSE(a.add_IWeapon(b1));

	map<int,WStat> testmap1 = a.get_invIWeapon();
	EXPECT_EQ(testmap1.size(),1);
	EXPECT_EQ(testmap1.find(w1.get_id()).second.second, 1);

	//tests if adding another of same item increases
	//its quantity by 1
	EXPECT_TRUE(a.add_IWeapon(w1));
	EXPECT_EQ(testmap1.size(), 1);
	EXPECT_EQ(testmap1.find(p1.get_id()).second.second, 2);

	//tests if adding a diff item increases map size by 1
	EXPECT_TRUE(a.add_IWeapon(w2));
	EXPECT_EQ(testmap1.size(), 2);
	EXPECT_EQ(testmap1.find(p2.get_id()).second, 1);
}

TEST_F(test_inventory, add_IPotion){
	EXPECT_FALSE(a.add_IPotion(w1));
	EXPECT_TRUE(a.add_IPotion(p1));
	EXPECT_FALSE(a.add_IPotion(b1));

	//tests map size to make sure map is 1 item long and
	//there is only 1 of that item in the inventory
	map<int, int> testmap2 = a.get_invIPotion();
	EXPECT_EQ(testmap2.size(), 1);
	EXPECT_EQ(testmap2.find(p1.get_id()).second, 1);

	//tests if adding another of the same item increases
	//its quantity by 1
	EXPECT_TRUE(a.add_IPotion(p1));
	EXPECT_EQ(testmap2.size(), 1);
	EXPECT_EQ(testmap2.find(p1.get_id()).second, 2);

	//tests if adding a diff item increases map size by 1
	EXPECT_TRUE(a.add_IPotion(p2));
	EXPECT_EQ(testmap2.size(), 2);
	EXPECT_EQ(testmap2.find(p2.get_id()).second, 1);
}

TEST_F(test_inventory, add_IBuff){
	EXPECT_FALSE(a.add_IBuff(w1));
	EXPECT_FALSE(a.add_IBuff(p1));
	EXPECT_TRUE(a.add_IBuff(b1));

	//tests map size to make sure map is 1 item long and
	//there is only 1 of that item in the inventory
	map<int,int> testmap3 = a.get_invIBuff();
	EXPECT_EQ(testmap3.size(),1);
	EXPECT_EQ(testmap3.find(b1.get_id()).second, 1);
	
	//tests if adding another of the same item increases
	//its quantity by 1
	EXPECT_TRUE(a.add_IBuff(b1));
	EXPECT_EQ(testmap3.size(), 1);
	EXPECT_EQ(testmap3.find(b1.get_id()).second, 2);

	//tests if adding a diff item increases map size by 1
	EXPECT_TRUE(a.add_IBuff(b2));
	EXPECT_EQ(testmap3.size(), 2);
	EXPECT_EQ(testmap3.find(b2.get_id()).second, 1);
}

TEST_F(test_inventory, remove_IWeapon){
	//adds 2 of one weapon and 1 of another weapon
	EXPECT_TRUE(a.add_IWeapon(w1));
	EXPECT_TRUE(a.add_IWeapon(w1));
	EXPECT_TRUE(a.add_IWeapon(w2));

	//checks if there are two of the first weapon
	map<int,WStat> testmap1 = a.get_invIWeapon();
	EXPECT_EQ(testmap1.size(),1);
	EXPECT_EQ(testmap1.find(w1.get_id()).second.second, 2);
	EXPECT_EQ(testmap1.find(w2.get_id()).second.second, 1);

	EXPECT_TRUE(a.remove_IWeapon(w1));
	EXPECT_EQ(testmap1.size(), 1);
	EXPECT_EQ(testmap1.find(w1.get_id()).second.second, 1);

	EXPECT_TRUE(a.remove_IWeapon(w1));
	EXPECT_EQ(testmap1.size(),0);
}

TEST_F(test_inventory, remove_IPotion){
	EXPECT_TRUE(a.add_IPotion(p1));
	EXPECT_TRUE(a.add_IPotion(p1));

	map<int,int> testmap2 = a.get_invIPotion();
	EXPECT_EQ(testmap2.size(),1);
	EXPECT_EQ(testmap2.invIPotion.find(p1.get_id()).second, 2);

	EXPECT_TRUE(a.remove_IPotion(p1));
	EXPECT_EQ(testmap2.size(), 1);
	EXPECT_EQ(testmap2.invIPotion.find(p1.get_id()).second, 1);

	EXPECT_TRUE(a.remove_IPotion(p1));
	EXPECT_EQ(testmap2.size(),0);
}

TEST_F(test_inventory, remove_IBuff){
	EXPECT_TRUE(a.add_IBuff(b1));
	EXPECT_TRUE(a.add_IBuff(b1));

	map<int,int> testmap3 = a.get_invIBuff();
	EXPECT_EQ(testmap3.size(),1);
	EXPECT_EQ(testmap3.invIBuff.find(b1.get_id()).second, 2);

	EXPECT_TRUE(a.remove_IBuff(b1));
	EXPECT_EQ(testmap3.size(), 1);
	EXPECT_EQ(testmap3.invIBuff.find(b1.get_id()).second, 1);

	EXPECT_TRUE(a.remove_IBuff(b1));
	EXPECT_EQ(testmap3.size(),0);
}

TEST_F(test_inventory,equip_IWeapon){


}

TEST_F(test_inventory,unequip_IWeapon){


}
