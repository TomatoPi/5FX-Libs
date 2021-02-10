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
 ///  \file jackwrap.cpp
 /// 
 ///  \author DAGO Kokri Esaïe <dago.esaie@protonmail.com>
 ///  \date 2021-02-04
 ///

#include "jackwrap.hpp"

namespace sfx {
  namespace jack {

    Client::~Client() {
      jack_deactivate(client);
      jack_client_close(client);
    }

    void Client::open(
      const std::string& name,
      std::initializer_list<std::tuple<
      jack_port_t**,
      const char*,
      const char*,
      unsigned long>> ports,
      JackProcessCallback callback) {

      JackStatus status;
      client = jack_client_open(name.c_str(), JackNullOption, &status);
      if (!client) {
        throw ClientOpenFailure{};
      }

      for (auto [port, name, type, flags] : ports) {
        *port = jack_port_register(client, name, type, flags, 0);
        if (nullptr == *port) {
          throw PortOpenFailure{};
        }
      }

      if (jack_set_process_callback(client, callback, nullptr)) {
        throw CallbackRegisterFailure{};
      }
    }

    void Client::activate() {
      if (jack_activate(client)) {
        throw ClientActivationFailure{};
      }
    }
  }
}