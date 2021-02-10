/*
 * Copyright (C) 2021 DAGO Kokri Esaïe <dago.esaie@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 ///
 ///  \file jackwrap.hpp
 /// 
 ///  \author DAGO Kokri Esaïe <dago.esaie@protonmail.com>
 ///  \date 2021-02-03
 ///

#pragma once

#include <jack/jack.h>

#include <initializer_list>
#include <string>
#include <tuple>

namespace sfx {
  namespace jack {


    struct ClientOpenFailure {};
    struct PortOpenFailure {};
    struct CallbackRegisterFailure {};
    struct ClientActivationFailure {};

    struct Client {

      jack_client_t* client;

      ~Client();

      void open(
        const std::string& name,
        std::initializer_list<std::tuple<
        jack_port_t**,
        const char*,
        const char*,
        unsigned long>> ports,
        JackProcessCallback callback);

      void activate();
    };
  }
}