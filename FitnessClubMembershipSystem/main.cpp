#include "ClubMembership.hpp"
#include "Member.hpp"
#include "System.hpp"
#include <iostream>

int main() {
	ClubMembership fitness{ MemberShip::STANDARD };
	ClubMembership fitness1{ MemberShip::PREMIUM };
	ClubMembership fitness2{ MemberShip::ALL_INCLUDED };
	
	Member member{ "Anna", "contact", &fitness };
	Member member1{ "Diana", "contact", &fitness1 };
	Member member2{ "Lana", "contact", &fitness2 };
	
	member.set_membership(&fitness);
	member1.set_membership(&fitness1);
	member2.set_membership(&fitness2);

	System run;
	run.add_members(&member);
	run.add_members(&member1);
	run.add_members(&member2);

	run.use_fitness(&member);
	run.use_fitness(&member);
	run.use_fitness(&member);
	run.use_fitness(&member);
	run.use_pool(&member);
	
	run.use_fitness(&member1);
	run.use_fitness(&member1);
	run.use_fitness(&member1);
	run.use_massage(&member1);
	run.use_massage(&member1);

	run.use_pool(&member2);
	run.use_pool(&member2);
	run.use_pool(&member2);
	run.use_pool(&member2);
	run.use_pool(&member2);
	run.use_fitness(&member2);
	run.use_fitness(&member2);
	run.use_massage(&member2);
	run.use_massage(&member2);
	run.use_massage(&member2);
	run.use_massage(&member2);

	run.add_stats(member);
	run.add_stats(member1);
	run.add_stats(member2);

	run.generate_monthly_stats();
}