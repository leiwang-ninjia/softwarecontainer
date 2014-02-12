/*
 *   Copyright (C) 2014 Pelagicore AB
 *   All rights reserved.
 */
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

#include "gateway.h"

/*! \brief Container base class
 *  \file container.h
 *
 *  Container base class for Pelagicontain
 */
class Container
{
public:
	Container ();
	Container(const std::string &name, const std::string &configFile);
	~Container();

	const char *name();
	std::vector<std::string> commands(const std::string &containedCommand,
		const std::vector<Gateway *> &gateways,
		const std::string &appRoot);

	std::string m_name;
    std::string m_configFile;
};

#endif //CONTAINER_H