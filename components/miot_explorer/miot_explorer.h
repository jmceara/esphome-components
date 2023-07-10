#pragma once

#include <map>
#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/switch/switch.h"
#include "../miot/miot.h"

namespace esphome {
namespace miot_explorer {

class MiotExplorer : public miot::MiotComponent, public text_sensor::TextSensor {
 public:
  void dump_config() override;

  uint16_t get_product_id() const override { return product_id_; }
  const char *get_product_code() const override { return "Explorer"; }

  bool process_mibeacon(const miot::MiBeacon &mib) override;

  void set_consumable(sensor::Sensor *consumable) { this->consumable_ = consumable; }

 protected:
  uint16_t product_id_;
  std::map<miot::MIID, EntityBase *> sensors_ = {};
  sensor::Sensor *consumable_{};

  bool process_object_(const miot::BLEObject &obj) override;
  void process_string_(miot::MIID miid, const std::string &name, const std::string &data);
  void process_uint8_(miot::MIID miid, const std::string &name, const optional<uint8_t> &value);
  void process_uint16_(miot::MIID miid, const std::string &name, const optional<uint16_t> &value);
  void process_uint32_(miot::MIID miid, const std::string &name, const optional<uint32_t> &value);
  void process_pairing_event_(miot::MIID miid, const std::string &name, const optional<miot::MIID> &value);
  void process_bool_(miot::MIID miid, const std::string &name, const optional<bool> &value);
  void process_float_(miot::MIID miid, const std::string &name, const optional<float> &value);
  void process_temperature_humidity_(miot::MIID miid, const std::string &name, const miot::TemperatureHumidity *th);
  void process_button_event_(miot::MIID miid, const std::string &name, const miot::ButtonEvent *button_event);
  void process_water_boil_(miot::MIID miid, const std::string &name, const miot::WaterBoil *water_boil);
};

}  // namespace miot_explorer
}  // namespace esphome
