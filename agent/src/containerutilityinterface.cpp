/*
 * Copyright (C) 2017 Pelagicore AB
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
 * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
 * For further information see LICENSE
 */

#include "containerutilityinterface.h"

#include "softwarecontainer-common.h"
#include "createdir.h"

#include <regex>

namespace softwarecontainer {
ContainerUtilityInterface::ContainerUtilityInterface(std::shared_ptr<Config> config)
    : m_config(std::move(config))
{
}

void ContainerUtilityInterface::checkWorkspace()
{
    const std::string rootDir = m_config->getStringValue("SoftwareContainer", "shared-mounts-dir");
    if (!isDirectory(rootDir)) {
        log_debug() << "Container root " << rootDir << " does not exist, trying to create";
        std::unique_ptr<CreateDir> createDirInstance(new CreateDir());
        if(!createDirInstance->createDirectory(rootDir)) {
            std::string message = "Failed to create container root directory";
            log_error() << message;
            throw SoftwareContainerError(message);
        }

        m_createDirList.push_back(std::move(createDirInstance));
    }
}


} //namespace
