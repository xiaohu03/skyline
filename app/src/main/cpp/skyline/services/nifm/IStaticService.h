// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::nifm {
    /**
     * @brief IStaticService or nifm:u is used by applications to open an IGeneralService instance for controlling the network connection
     * @url https://switchbrew.org/wiki/Network_Interface_services#IGeneralService
     */
    class IStaticService : public BaseService {
      public:
        IStaticService(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Opens an IGeneralService that can be used by applications to control the network connection
         * @url https://switchbrew.org/wiki/Network_Interface_services#CreateGeneralServiceOld
         */
        Result CreateGeneralService(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x4, IStaticService, CreateGeneralService),
            SFUNC(0x5, IStaticService, CreateGeneralService)
        )
    };
}
