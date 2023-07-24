#include "Portal.hpp"

void Portal::add_jobs(Job* job) {
	m_jobs.push_back(job);
	for (auto user : m_users) {
		if (job->get_title() == user->get_resume()) {
			user->add_notification("This jobs matches with your resume.\n" +
				job->get_title() + "\n"+ job->get_company() + "\n" +
				job->get_description() + "\n" + job->get_requirments() + "\n" +
				std::to_string(job->get_salary()) + "\n");
		}
	}
}

std::vector<Job*> Portal::get_jobs() const {
	return m_jobs;
}

void Portal::add_user(User* user) {
	m_users.push_back(user);
}

std::vector<User*> Portal::get_users() const {
	return m_users;
}

void Portal::job_fill(const User& user) {
	for (auto job : get_jobs()) {
		if (user.get_resume() == job->get_title() && user.get_salaray() == job->get_salary()) {
			job->set_status(false);
		}
	}

	m_jobs.erase(std::remove_if(m_jobs.begin(), m_jobs.end(), [](Job* job) {
		if (job->get_status() == false) return true; return false; }), m_jobs.end());
}

void Portal::search_by_title(const std::string& title) {
	for (auto job : get_jobs()) {
		if (job->get_title() == title) {
			std::cout << job->get_company() << std::endl;
			std::cout << job->get_description() << std::endl;
			std::cout << job->get_requirments() << std::endl;
			std::cout << job->get_salary() << std::endl;
		}
	}
}

void Portal::search_by_company(const std::string& company) {
	for (auto job : get_jobs()) {
		if (job->get_company() == company) {
			std::cout << job->get_title() << std::endl;
			std::cout << job->get_description() << std::endl;
			std::cout << job->get_requirments() << std::endl;
			std::cout << job->get_salary() << std::endl;
		}
	}
}

void Portal::search_by_salary(const int salary) {
	for (auto job : get_jobs()) {
		if (job->get_salary() == salary) {
			std::cout << job->get_company() << std::endl;
			std::cout << job->get_title() << std::endl;
			std::cout << job->get_description() << std::endl;
			std::cout << job->get_requirments() << std::endl;
		}
	}
}