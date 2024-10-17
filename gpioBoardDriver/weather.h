/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: weather.proto
 */

// This file is generated. Please do not edit!
#ifndef WEATHER_H
#define WEATHER_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions

namespace weather {

class Data final: public ::EmbeddedProto::MessageInterface
{
  public:
    Data() = default;
    Data(const Data& rhs )
    {
      set_temperature(rhs.get_temperature());
      set_humidity(rhs.get_humidity());
      set_air_pressure(rhs.get_air_pressure());
      set_wind_speed(rhs.get_wind_speed());
      set_wind_direction(rhs.get_wind_direction());
    }

    Data(const Data&& rhs ) noexcept
    {
      set_temperature(rhs.get_temperature());
      set_humidity(rhs.get_humidity());
      set_air_pressure(rhs.get_air_pressure());
      set_wind_speed(rhs.get_wind_speed());
      set_wind_direction(rhs.get_wind_direction());
    }

    ~Data() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TEMPERATURE = 1,
      HUMIDITY = 2,
      AIR_PRESSURE = 3,
      WIND_SPEED = 4,
      WIND_DIRECTION = 5
    };

    Data& operator=(const Data& rhs)
    {
      set_temperature(rhs.get_temperature());
      set_humidity(rhs.get_humidity());
      set_air_pressure(rhs.get_air_pressure());
      set_wind_speed(rhs.get_wind_speed());
      set_wind_direction(rhs.get_wind_direction());
      return *this;
    }

    Data& operator=(const Data&& rhs) noexcept
    {
      set_temperature(rhs.get_temperature());
      set_humidity(rhs.get_humidity());
      set_air_pressure(rhs.get_air_pressure());
      set_wind_speed(rhs.get_wind_speed());
      set_wind_direction(rhs.get_wind_direction());
      return *this;
    }

    static constexpr char const* TEMPERATURE_NAME = "temperature";
    inline void clear_temperature() { temperature_.clear(); }
    inline void set_temperature(const float& value) { temperature_ = value; }
    inline void set_temperature(const float&& value) { temperature_ = value; }
    inline float& mutable_temperature() { return temperature_.get(); }
    inline const float& get_temperature() const { return temperature_.get(); }
    inline float temperature() const { return temperature_.get(); }

    static constexpr char const* HUMIDITY_NAME = "humidity";
    inline void clear_humidity() { humidity_.clear(); }
    inline void set_humidity(const float& value) { humidity_ = value; }
    inline void set_humidity(const float&& value) { humidity_ = value; }
    inline float& mutable_humidity() { return humidity_.get(); }
    inline const float& get_humidity() const { return humidity_.get(); }
    inline float humidity() const { return humidity_.get(); }

    static constexpr char const* AIR_PRESSURE_NAME = "air_pressure";
    inline void clear_air_pressure() { air_pressure_.clear(); }
    inline void set_air_pressure(const int32_t& value) { air_pressure_ = value; }
    inline void set_air_pressure(const int32_t&& value) { air_pressure_ = value; }
    inline int32_t& mutable_air_pressure() { return air_pressure_.get(); }
    inline const int32_t& get_air_pressure() const { return air_pressure_.get(); }
    inline int32_t air_pressure() const { return air_pressure_.get(); }

    static constexpr char const* WIND_SPEED_NAME = "wind_speed";
    inline void clear_wind_speed() { wind_speed_.clear(); }
    inline void set_wind_speed(const float& value) { wind_speed_ = value; }
    inline void set_wind_speed(const float&& value) { wind_speed_ = value; }
    inline float& mutable_wind_speed() { return wind_speed_.get(); }
    inline const float& get_wind_speed() const { return wind_speed_.get(); }
    inline float wind_speed() const { return wind_speed_.get(); }

    static constexpr char const* WIND_DIRECTION_NAME = "wind_direction";
    inline void clear_wind_direction() { wind_direction_.clear(); }
    inline void set_wind_direction(const float& value) { wind_direction_ = value; }
    inline void set_wind_direction(const float&& value) { wind_direction_ = value; }
    inline float& mutable_wind_direction() { return wind_direction_.get(); }
    inline const float& get_wind_direction() const { return wind_direction_.get(); }
    inline float wind_direction() const { return wind_direction_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TEMPERATURE), buffer, false);
      }

      if((0.0 != humidity_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = humidity_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HUMIDITY), buffer, false);
      }

      if((0 != air_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = air_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::AIR_PRESSURE), buffer, false);
      }

      if((0.0 != wind_speed_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = wind_speed_.serialize_with_id(static_cast<uint32_t>(FieldNumber::WIND_SPEED), buffer, false);
      }

      if((0.0 != wind_direction_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = wind_direction_.serialize_with_id(static_cast<uint32_t>(FieldNumber::WIND_DIRECTION), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TEMPERATURE:
            return_value = temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::HUMIDITY:
            return_value = humidity_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::AIR_PRESSURE:
            return_value = air_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::WIND_SPEED:
            return_value = wind_speed_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::WIND_DIRECTION:
            return_value = wind_direction_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_temperature();
      clear_humidity();
      clear_air_pressure();
      clear_wind_speed();
      clear_wind_direction();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TEMPERATURE:
          name = TEMPERATURE_NAME;
          break;
        case FieldNumber::HUMIDITY:
          name = HUMIDITY_NAME;
          break;
        case FieldNumber::AIR_PRESSURE:
          name = AIR_PRESSURE_NAME;
          break;
        case FieldNumber::WIND_SPEED:
          name = WIND_SPEED_NAME;
          break;
        case FieldNumber::WIND_DIRECTION:
          name = WIND_DIRECTION_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = temperature_.to_string(left_chars, indent_level + 2, TEMPERATURE_NAME, true);
      left_chars = humidity_.to_string(left_chars, indent_level + 2, HUMIDITY_NAME, false);
      left_chars = air_pressure_.to_string(left_chars, indent_level + 2, AIR_PRESSURE_NAME, false);
      left_chars = wind_speed_.to_string(left_chars, indent_level + 2, WIND_SPEED_NAME, false);
      left_chars = wind_direction_.to_string(left_chars, indent_level + 2, WIND_DIRECTION_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::floatfixed temperature_ = 0.0;
      EmbeddedProto::floatfixed humidity_ = 0.0;
      EmbeddedProto::int32 air_pressure_ = 0;
      EmbeddedProto::floatfixed wind_speed_ = 0.0;
      EmbeddedProto::floatfixed wind_direction_ = 0.0;

};

class Settings final: public ::EmbeddedProto::MessageInterface
{
  public:
    Settings() = default;
    Settings(const Settings& rhs )
    {
      set_update_period_sec(rhs.get_update_period_sec());
    }

    Settings(const Settings&& rhs ) noexcept
    {
      set_update_period_sec(rhs.get_update_period_sec());
    }

    ~Settings() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      UPDATE_PERIOD_SEC = 1
    };

    Settings& operator=(const Settings& rhs)
    {
      set_update_period_sec(rhs.get_update_period_sec());
      return *this;
    }

    Settings& operator=(const Settings&& rhs) noexcept
    {
      set_update_period_sec(rhs.get_update_period_sec());
      return *this;
    }

    static constexpr char const* UPDATE_PERIOD_SEC_NAME = "update_period_sec";
    inline void clear_update_period_sec() { update_period_sec_.clear(); }
    inline void set_update_period_sec(const int32_t& value) { update_period_sec_ = value; }
    inline void set_update_period_sec(const int32_t&& value) { update_period_sec_ = value; }
    inline int32_t& mutable_update_period_sec() { return update_period_sec_.get(); }
    inline const int32_t& get_update_period_sec() const { return update_period_sec_.get(); }
    inline int32_t update_period_sec() const { return update_period_sec_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != update_period_sec_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = update_period_sec_.serialize_with_id(static_cast<uint32_t>(FieldNumber::UPDATE_PERIOD_SEC), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::UPDATE_PERIOD_SEC:
            return_value = update_period_sec_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_update_period_sec();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::UPDATE_PERIOD_SEC:
          name = UPDATE_PERIOD_SEC_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = update_period_sec_.to_string(left_chars, indent_level + 2, UPDATE_PERIOD_SEC_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 update_period_sec_ = 0;

};

template<
    uint32_t DataHistory_data_REP_LENGTH
>
class DataHistory final: public ::EmbeddedProto::MessageInterface
{
  public:
    DataHistory() = default;
    DataHistory(const DataHistory& rhs )
    {
      set_data(rhs.get_data());
    }

    DataHistory(const DataHistory&& rhs ) noexcept
    {
      set_data(rhs.get_data());
    }

    ~DataHistory() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DATA = 1
    };

    DataHistory& operator=(const DataHistory& rhs)
    {
      set_data(rhs.get_data());
      return *this;
    }

    DataHistory& operator=(const DataHistory&& rhs) noexcept
    {
      set_data(rhs.get_data());
      return *this;
    }

    static constexpr char const* DATA_NAME = "data";
    inline const Data& data(uint32_t index) const { return data_[index]; }
    inline void clear_data() { data_.clear(); }
    inline void set_data(uint32_t index, const Data& value) { data_.set(index, value); }
    inline void set_data(uint32_t index, const Data&& value) { data_.set(index, value); }
    inline void set_data(const ::EmbeddedProto::RepeatedFieldFixedSize<Data, DataHistory_data_REP_LENGTH>& values) { data_ = values; }
    inline void add_data(const Data& value) { data_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<Data, DataHistory_data_REP_LENGTH>& mutable_data() { return data_; }
    inline Data& mutable_data(uint32_t index) { return data_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<Data, DataHistory_data_REP_LENGTH>& get_data() const { return data_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<Data, DataHistory_data_REP_LENGTH>& data() const { return data_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = data_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DATA), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::DATA:
            return_value = data_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_data();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::DATA:
          name = DATA_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = data_.to_string(left_chars, indent_level + 2, DATA_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::RepeatedFieldFixedSize<Data, DataHistory_data_REP_LENGTH> data_;

};

} // End of namespace weather
#endif // WEATHER_H