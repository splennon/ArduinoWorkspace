/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: serial.proto
 */

// This file is generated. Please do not edit!
#ifndef SERIAL_H
#define SERIAL_H

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
#include "timestamp.h"

namespace serial {

enum class PinType : uint32_t
{
  DIGITAL_IN = 0,
  DIGITAL_OUT = 1,
  ANALOG_IN = 2,
  ANALOG_OUT = 3,
  COSINE = 4,
  BUFFER = 5,
  PWM = 6
};

class Config final: public ::EmbeddedProto::MessageInterface
{
  public:
    Config() = default;
    Config(const Config& rhs )
    {
      set_pin(rhs.get_pin());
      set_type(rhs.get_type());
      set_interrupt(rhs.get_interrupt());
    }

    Config(const Config&& rhs ) noexcept
    {
      set_pin(rhs.get_pin());
      set_type(rhs.get_type());
      set_interrupt(rhs.get_interrupt());
    }

    ~Config() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      PIN = 1,
      TYPE = 2,
      INTERRUPT = 3
    };

    Config& operator=(const Config& rhs)
    {
      set_pin(rhs.get_pin());
      set_type(rhs.get_type());
      set_interrupt(rhs.get_interrupt());
      return *this;
    }

    Config& operator=(const Config&& rhs) noexcept
    {
      set_pin(rhs.get_pin());
      set_type(rhs.get_type());
      set_interrupt(rhs.get_interrupt());
      return *this;
    }

    static constexpr char const* PIN_NAME = "pin";
    inline void clear_pin() { pin_.clear(); }
    inline void set_pin(const uint32_t& value) { pin_ = value; }
    inline void set_pin(const uint32_t&& value) { pin_ = value; }
    inline uint32_t& mutable_pin() { return pin_.get(); }
    inline const uint32_t& get_pin() const { return pin_.get(); }
    inline uint32_t pin() const { return pin_.get(); }

    static constexpr char const* TYPE_NAME = "type";
    inline void clear_type() { type_.clear(); }
    inline void set_type(const PinType& value) { type_ = value; }
    inline void set_type(const PinType&& value) { type_ = value; }
    inline const PinType& get_type() const { return type_.get(); }
    inline PinType type() const { return type_.get(); }

    static constexpr char const* INTERRUPT_NAME = "interrupt";
    inline void clear_interrupt() { interrupt_.clear(); }
    inline void set_interrupt(const bool& value) { interrupt_ = value; }
    inline void set_interrupt(const bool&& value) { interrupt_ = value; }
    inline bool& mutable_interrupt() { return interrupt_.get(); }
    inline const bool& get_interrupt() const { return interrupt_.get(); }
    inline bool interrupt() const { return interrupt_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != pin_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pin_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PIN), buffer, false);
      }

      if((static_cast<PinType>(0) != type_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = type_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TYPE), buffer, false);
      }

      if((false != interrupt_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = interrupt_.serialize_with_id(static_cast<uint32_t>(FieldNumber::INTERRUPT), buffer, false);
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
          case FieldNumber::PIN:
            return_value = pin_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TYPE:
            return_value = type_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::INTERRUPT:
            return_value = interrupt_.deserialize_check_type(buffer, wire_type);
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
      clear_pin();
      clear_type();
      clear_interrupt();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::PIN:
          name = PIN_NAME;
          break;
        case FieldNumber::TYPE:
          name = TYPE_NAME;
          break;
        case FieldNumber::INTERRUPT:
          name = INTERRUPT_NAME;
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

      left_chars = pin_.to_string(left_chars, indent_level + 2, PIN_NAME, true);
      left_chars = type_.to_string(left_chars, indent_level + 2, TYPE_NAME, false);
      left_chars = interrupt_.to_string(left_chars, indent_level + 2, INTERRUPT_NAME, false);
  
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


      EmbeddedProto::uint32 pin_ = 0U;
      EmbeddedProto::enumeration<PinType> type_ = static_cast<PinType>(0);
      EmbeddedProto::boolean interrupt_ = false;

};

class Deconfig final: public ::EmbeddedProto::MessageInterface
{
  public:
    Deconfig() = default;
    Deconfig(const Deconfig& rhs )
    {
      set_pin(rhs.get_pin());
    }

    Deconfig(const Deconfig&& rhs ) noexcept
    {
      set_pin(rhs.get_pin());
    }

    ~Deconfig() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      PIN = 1
    };

    Deconfig& operator=(const Deconfig& rhs)
    {
      set_pin(rhs.get_pin());
      return *this;
    }

    Deconfig& operator=(const Deconfig&& rhs) noexcept
    {
      set_pin(rhs.get_pin());
      return *this;
    }

    static constexpr char const* PIN_NAME = "pin";
    inline void clear_pin() { pin_.clear(); }
    inline void set_pin(const uint32_t& value) { pin_ = value; }
    inline void set_pin(const uint32_t&& value) { pin_ = value; }
    inline uint32_t& mutable_pin() { return pin_.get(); }
    inline const uint32_t& get_pin() const { return pin_.get(); }
    inline uint32_t pin() const { return pin_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != pin_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pin_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PIN), buffer, false);
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
          case FieldNumber::PIN:
            return_value = pin_.deserialize_check_type(buffer, wire_type);
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
      clear_pin();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::PIN:
          name = PIN_NAME;
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

      left_chars = pin_.to_string(left_chars, indent_level + 2, PIN_NAME, true);
  
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


      EmbeddedProto::uint32 pin_ = 0U;

};

class Dump final: public ::EmbeddedProto::MessageInterface
{
  public:
    Dump() = default;
    Dump(const Dump& rhs )
    {
    }

    Dump(const Dump&& rhs ) noexcept
    {
    }

    ~Dump() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
    };

    Dump& operator=(const Dump& rhs)
    {
      return *this;
    }

    Dump& operator=(const Dump&& rhs) noexcept
    {
      return *this;
    }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

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

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
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



};

template<
    uint32_t IntArray_entry_REP_LENGTH
>
class IntArray final: public ::EmbeddedProto::MessageInterface
{
  public:
    IntArray() = default;
    IntArray(const IntArray& rhs )
    {
      set_entry(rhs.get_entry());
    }

    IntArray(const IntArray&& rhs ) noexcept
    {
      set_entry(rhs.get_entry());
    }

    ~IntArray() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ENTRY = 1
    };

    IntArray& operator=(const IntArray& rhs)
    {
      set_entry(rhs.get_entry());
      return *this;
    }

    IntArray& operator=(const IntArray&& rhs) noexcept
    {
      set_entry(rhs.get_entry());
      return *this;
    }

    static constexpr char const* ENTRY_NAME = "entry";
    inline const EmbeddedProto::uint32& entry(uint32_t index) const { return entry_[index]; }
    inline void clear_entry() { entry_.clear(); }
    inline void set_entry(uint32_t index, const EmbeddedProto::uint32& value) { entry_.set(index, value); }
    inline void set_entry(uint32_t index, const EmbeddedProto::uint32&& value) { entry_.set(index, value); }
    inline void set_entry(const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, IntArray_entry_REP_LENGTH>& values) { entry_ = values; }
    inline void add_entry(const EmbeddedProto::uint32& value) { entry_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, IntArray_entry_REP_LENGTH>& mutable_entry() { return entry_; }
    inline EmbeddedProto::uint32& mutable_entry(uint32_t index) { return entry_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, IntArray_entry_REP_LENGTH>& get_entry() const { return entry_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, IntArray_entry_REP_LENGTH>& entry() const { return entry_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = entry_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ENTRY), buffer, false);
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
          case FieldNumber::ENTRY:
            return_value = entry_.deserialize_check_type(buffer, wire_type);
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
      clear_entry();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ENTRY:
          name = ENTRY_NAME;
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

      left_chars = entry_.to_string(left_chars, indent_level + 2, ENTRY_NAME, true);
  
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


      ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, IntArray_entry_REP_LENGTH> entry_;

};

template<
    uint32_t Read_pin_REP_LENGTH
>
class Read final: public ::EmbeddedProto::MessageInterface
{
  public:
    Read() = default;
    Read(const Read& rhs )
    {
      set_pin(rhs.get_pin());
    }

    Read(const Read&& rhs ) noexcept
    {
      set_pin(rhs.get_pin());
    }

    ~Read() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      PIN = 1
    };

    Read& operator=(const Read& rhs)
    {
      set_pin(rhs.get_pin());
      return *this;
    }

    Read& operator=(const Read&& rhs) noexcept
    {
      set_pin(rhs.get_pin());
      return *this;
    }

    static constexpr char const* PIN_NAME = "pin";
    inline const EmbeddedProto::uint32& pin(uint32_t index) const { return pin_[index]; }
    inline void clear_pin() { pin_.clear(); }
    inline void set_pin(uint32_t index, const EmbeddedProto::uint32& value) { pin_.set(index, value); }
    inline void set_pin(uint32_t index, const EmbeddedProto::uint32&& value) { pin_.set(index, value); }
    inline void set_pin(const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Read_pin_REP_LENGTH>& values) { pin_ = values; }
    inline void add_pin(const EmbeddedProto::uint32& value) { pin_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Read_pin_REP_LENGTH>& mutable_pin() { return pin_; }
    inline EmbeddedProto::uint32& mutable_pin(uint32_t index) { return pin_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Read_pin_REP_LENGTH>& get_pin() const { return pin_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Read_pin_REP_LENGTH>& pin() const { return pin_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = pin_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PIN), buffer, false);
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
          case FieldNumber::PIN:
            return_value = pin_.deserialize_check_type(buffer, wire_type);
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
      clear_pin();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::PIN:
          name = PIN_NAME;
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

      left_chars = pin_.to_string(left_chars, indent_level + 2, PIN_NAME, true);
  
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


      ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Read_pin_REP_LENGTH> pin_;

};

template<
    uint32_t BoundData_buffer_IntArray_entry_REP_LENGTH
>
class BoundData final: public ::EmbeddedProto::MessageInterface
{
  public:
    BoundData() = default;
    BoundData(const BoundData& rhs )
    {
      set_pin(rhs.get_pin());
      set_time(rhs.get_time());
      if(rhs.get_which_data() != which_data_)
      {
        // First delete the old object in the oneof.
        clear_data();
      }

      switch(rhs.get_which_data())
      {
        case FieldNumber::NUMBER:
          set_number(rhs.get_number());
          break;

        case FieldNumber::BOOLEAN:
          set_boolean(rhs.get_boolean());
          break;

        case FieldNumber::BUFFER:
          set_buffer(rhs.get_buffer());
          break;

        default:
          break;
      }

    }

    BoundData(const BoundData&& rhs ) noexcept
    {
      set_pin(rhs.get_pin());
      set_time(rhs.get_time());
      if(rhs.get_which_data() != which_data_)
      {
        // First delete the old object in the oneof.
        clear_data();
      }

      switch(rhs.get_which_data())
      {
        case FieldNumber::NUMBER:
          set_number(rhs.get_number());
          break;

        case FieldNumber::BOOLEAN:
          set_boolean(rhs.get_boolean());
          break;

        case FieldNumber::BUFFER:
          set_buffer(rhs.get_buffer());
          break;

        default:
          break;
      }

    }

    ~BoundData() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      PIN = 1,
      TIME = 2,
      NUMBER = 3,
      BOOLEAN = 4,
      BUFFER = 5
    };

    BoundData& operator=(const BoundData& rhs)
    {
      set_pin(rhs.get_pin());
      set_time(rhs.get_time());
      if(rhs.get_which_data() != which_data_)
      {
        // First delete the old object in the oneof.
        clear_data();
      }

      switch(rhs.get_which_data())
      {
        case FieldNumber::NUMBER:
          set_number(rhs.get_number());
          break;

        case FieldNumber::BOOLEAN:
          set_boolean(rhs.get_boolean());
          break;

        case FieldNumber::BUFFER:
          set_buffer(rhs.get_buffer());
          break;

        default:
          break;
      }

      return *this;
    }

    BoundData& operator=(const BoundData&& rhs) noexcept
    {
      set_pin(rhs.get_pin());
      set_time(rhs.get_time());
      if(rhs.get_which_data() != which_data_)
      {
        // First delete the old object in the oneof.
        clear_data();
      }

      switch(rhs.get_which_data())
      {
        case FieldNumber::NUMBER:
          set_number(rhs.get_number());
          break;

        case FieldNumber::BOOLEAN:
          set_boolean(rhs.get_boolean());
          break;

        case FieldNumber::BUFFER:
          set_buffer(rhs.get_buffer());
          break;

        default:
          break;
      }

      return *this;
    }

    static constexpr char const* PIN_NAME = "pin";
    inline void clear_pin() { pin_.clear(); }
    inline void set_pin(const uint32_t& value) { pin_ = value; }
    inline void set_pin(const uint32_t&& value) { pin_ = value; }
    inline uint32_t& mutable_pin() { return pin_.get(); }
    inline const uint32_t& get_pin() const { return pin_.get(); }
    inline uint32_t pin() const { return pin_.get(); }

    static constexpr char const* TIME_NAME = "time";
    inline void clear_time() { time_.clear(); }
    inline void set_time(const google::protobuf::Timestamp& value) { time_ = value; }
    inline void set_time(const google::protobuf::Timestamp&& value) { time_ = value; }
    inline google::protobuf::Timestamp& mutable_time() { return time_; }
    inline const google::protobuf::Timestamp& get_time() const { return time_; }
    inline const google::protobuf::Timestamp& time() const { return time_; }

    FieldNumber get_which_data() const { return which_data_; }

    static constexpr char const* NUMBER_NAME = "number";
    inline bool has_number() const
    {
      return FieldNumber::NUMBER == which_data_;
    }
    inline void clear_number()
    {
      if(FieldNumber::NUMBER == which_data_)
      {
        which_data_ = FieldNumber::NOT_SET;
        ::EmbeddedProto::destroy_at(&data_.number_);
      }
    }
    inline void set_number(const uint32_t& value)
    {
      if(FieldNumber::NUMBER != which_data_)
      {
        init_data(FieldNumber::NUMBER);
      }
      data_.number_ = value;
    }
    inline void set_number(const uint32_t&& value)
    {
      if(FieldNumber::NUMBER != which_data_)
      {
        init_data(FieldNumber::NUMBER);
      }
      data_.number_ = value;
    }
    inline const uint32_t& get_number() const { return data_.number_.get(); }
    inline uint32_t number() const { return data_.number_.get(); }

    static constexpr char const* BOOLEAN_NAME = "boolean";
    inline bool has_boolean() const
    {
      return FieldNumber::BOOLEAN == which_data_;
    }
    inline void clear_boolean()
    {
      if(FieldNumber::BOOLEAN == which_data_)
      {
        which_data_ = FieldNumber::NOT_SET;
        ::EmbeddedProto::destroy_at(&data_.boolean_);
      }
    }
    inline void set_boolean(const bool& value)
    {
      if(FieldNumber::BOOLEAN != which_data_)
      {
        init_data(FieldNumber::BOOLEAN);
      }
      data_.boolean_ = value;
    }
    inline void set_boolean(const bool&& value)
    {
      if(FieldNumber::BOOLEAN != which_data_)
      {
        init_data(FieldNumber::BOOLEAN);
      }
      data_.boolean_ = value;
    }
    inline const bool& get_boolean() const { return data_.boolean_.get(); }
    inline bool boolean() const { return data_.boolean_.get(); }

    static constexpr char const* BUFFER_NAME = "buffer";
    inline bool has_buffer() const
    {
      return FieldNumber::BUFFER == which_data_;
    }
    inline void clear_buffer()
    {
      if(FieldNumber::BUFFER == which_data_)
      {
        which_data_ = FieldNumber::NOT_SET;
        data_.buffer_.~IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>();
      }
    }
    inline void set_buffer(const IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>& value)
    {
      if(FieldNumber::BUFFER != which_data_)
      {
        init_data(FieldNumber::BUFFER);
      }
      data_.buffer_ = value;
    }
    inline void set_buffer(const IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>&& value)
    {
      if(FieldNumber::BUFFER != which_data_)
      {
        init_data(FieldNumber::BUFFER);
      }
      data_.buffer_ = value;
    }
    inline IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>& mutable_buffer()
    {
      if(FieldNumber::BUFFER != which_data_)
      {
        init_data(FieldNumber::BUFFER);
      }
      return data_.buffer_;
    }
    inline const IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>& get_buffer() const { return data_.buffer_; }
    inline const IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>& buffer() const { return data_.buffer_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != pin_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pin_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PIN), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = time_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIME), buffer, false);
      }

      switch(which_data_)
      {
        case FieldNumber::NUMBER:
          if(has_number() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = data_.number_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NUMBER), buffer, true);
          }
          break;

        case FieldNumber::BOOLEAN:
          if(has_boolean() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = data_.boolean_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BOOLEAN), buffer, true);
          }
          break;

        case FieldNumber::BUFFER:
          if(has_buffer() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = data_.buffer_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BUFFER), buffer, true);
          }
          break;

        default:
          break;
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
          case FieldNumber::PIN:
            return_value = pin_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TIME:
            return_value = time_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NUMBER:
          case FieldNumber::BOOLEAN:
          case FieldNumber::BUFFER:
            return_value = deserialize_data(id_tag, buffer, wire_type);
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
      clear_pin();
      clear_time();
      clear_data();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::PIN:
          name = PIN_NAME;
          break;
        case FieldNumber::TIME:
          name = TIME_NAME;
          break;
        case FieldNumber::NUMBER:
          name = NUMBER_NAME;
          break;
        case FieldNumber::BOOLEAN:
          name = BOOLEAN_NAME;
          break;
        case FieldNumber::BUFFER:
          name = BUFFER_NAME;
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

      left_chars = pin_.to_string(left_chars, indent_level + 2, PIN_NAME, true);
      left_chars = time_.to_string(left_chars, indent_level + 2, TIME_NAME, false);
      left_chars = to_string_data(left_chars, indent_level + 2, false);
  
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


      EmbeddedProto::uint32 pin_ = 0U;
      google::protobuf::Timestamp time_;

      FieldNumber which_data_ = FieldNumber::NOT_SET;
      union data
      {
        data() {}
        ~data() {}
        EmbeddedProto::uint32 number_;
        EmbeddedProto::boolean boolean_;
        IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH> buffer_;
      };
      data data_;

      void init_data(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_data_)
        {
          // First delete the old object in the oneof.
          clear_data();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::NUMBER:
            new(&data_.number_) EmbeddedProto::uint32;
            break;

          case FieldNumber::BOOLEAN:
            new(&data_.boolean_) EmbeddedProto::boolean;
            break;

          case FieldNumber::BUFFER:
            new(&data_.buffer_) IntArray<BoundData_buffer_IntArray_entry_REP_LENGTH>;
            break;

          default:
            break;
         }

         which_data_ = field_id;
      }

      void clear_data()
      {
        switch(which_data_)
        {
          case FieldNumber::NUMBER:
            ::EmbeddedProto::destroy_at(&data_.number_);
            break;
          case FieldNumber::BOOLEAN:
            ::EmbeddedProto::destroy_at(&data_.boolean_);
            break;
          case FieldNumber::BUFFER:
            ::EmbeddedProto::destroy_at(&data_.buffer_);
            break;
          default:
            break;
        }
        which_data_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_data(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_data_)
        {
          init_data(field_id);
        }

        switch(which_data_)
        {
          case FieldNumber::NUMBER:
            return_value = data_.number_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::BOOLEAN:
            return_value = data_.boolean_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::BUFFER:
            return_value = data_.buffer_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_data();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_data(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_data_)
        {
          case FieldNumber::NUMBER:
            left_chars = data_.number_.to_string(left_chars, indent_level, NUMBER_NAME, first_field);
            break;
          case FieldNumber::BOOLEAN:
            left_chars = data_.boolean_.to_string(left_chars, indent_level, BOOLEAN_NAME, first_field);
            break;
          case FieldNumber::BUFFER:
            left_chars = data_.buffer_.to_string(left_chars, indent_level, BUFFER_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

template<
    uint32_t BoundDataArray_entry_REP_LENGTH, 
    uint32_t BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH
>
class BoundDataArray final: public ::EmbeddedProto::MessageInterface
{
  public:
    BoundDataArray() = default;
    BoundDataArray(const BoundDataArray& rhs )
    {
      set_entry(rhs.get_entry());
    }

    BoundDataArray(const BoundDataArray&& rhs ) noexcept
    {
      set_entry(rhs.get_entry());
    }

    ~BoundDataArray() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ENTRY = 1
    };

    BoundDataArray& operator=(const BoundDataArray& rhs)
    {
      set_entry(rhs.get_entry());
      return *this;
    }

    BoundDataArray& operator=(const BoundDataArray&& rhs) noexcept
    {
      set_entry(rhs.get_entry());
      return *this;
    }

    static constexpr char const* ENTRY_NAME = "entry";
    inline const BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& entry(uint32_t index) const { return entry_[index]; }
    inline void clear_entry() { entry_.clear(); }
    inline void set_entry(uint32_t index, const BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& value) { entry_.set(index, value); }
    inline void set_entry(uint32_t index, const BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>&& value) { entry_.set(index, value); }
    inline void set_entry(const ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>, BoundDataArray_entry_REP_LENGTH>& values) { entry_ = values; }
    inline void add_entry(const BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& value) { entry_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>, BoundDataArray_entry_REP_LENGTH>& mutable_entry() { return entry_; }
    inline BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& mutable_entry(uint32_t index) { return entry_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>, BoundDataArray_entry_REP_LENGTH>& get_entry() const { return entry_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>, BoundDataArray_entry_REP_LENGTH>& entry() const { return entry_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = entry_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ENTRY), buffer, false);
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
          case FieldNumber::ENTRY:
            return_value = entry_.deserialize_check_type(buffer, wire_type);
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
      clear_entry();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ENTRY:
          name = ENTRY_NAME;
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

      left_chars = entry_.to_string(left_chars, indent_level + 2, ENTRY_NAME, true);
  
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


      ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>, BoundDataArray_entry_REP_LENGTH> entry_;

};

template<
    uint32_t Write_data_REP_LENGTH, 
    uint32_t Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH
>
class Write final: public ::EmbeddedProto::MessageInterface
{
  public:
    Write() = default;
    Write(const Write& rhs )
    {
      set_data(rhs.get_data());
    }

    Write(const Write&& rhs ) noexcept
    {
      set_data(rhs.get_data());
    }

    ~Write() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DATA = 1
    };

    Write& operator=(const Write& rhs)
    {
      set_data(rhs.get_data());
      return *this;
    }

    Write& operator=(const Write&& rhs) noexcept
    {
      set_data(rhs.get_data());
      return *this;
    }

    static constexpr char const* DATA_NAME = "data";
    inline const BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& data(uint32_t index) const { return data_[index]; }
    inline void clear_data() { data_.clear(); }
    inline void set_data(uint32_t index, const BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& value) { data_.set(index, value); }
    inline void set_data(uint32_t index, const BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>&& value) { data_.set(index, value); }
    inline void set_data(const ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>, Write_data_REP_LENGTH>& values) { data_ = values; }
    inline void add_data(const BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& value) { data_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>, Write_data_REP_LENGTH>& mutable_data() { return data_; }
    inline BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& mutable_data(uint32_t index) { return data_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>, Write_data_REP_LENGTH>& get_data() const { return data_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>, Write_data_REP_LENGTH>& data() const { return data_; }


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


      ::EmbeddedProto::RepeatedFieldFixedSize<BoundData<Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>, Write_data_REP_LENGTH> data_;

};

template<
    uint32_t BoardMessage_data_BoundDataArray_entry_REP_LENGTH, 
    uint32_t BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH, 
    uint32_t BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH
>
class BoardMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    BoardMessage() = default;
    BoardMessage(const BoardMessage& rhs )
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::DATA:
          set_data(rhs.get_data());
          break;

        case FieldNumber::INTERRUPT:
          set_interrupt(rhs.get_interrupt());
          break;

        default:
          break;
      }

    }

    BoardMessage(const BoardMessage&& rhs ) noexcept
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::DATA:
          set_data(rhs.get_data());
          break;

        case FieldNumber::INTERRUPT:
          set_interrupt(rhs.get_interrupt());
          break;

        default:
          break;
      }

    }

    ~BoardMessage() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DATA = 1,
      INTERRUPT = 2
    };

    BoardMessage& operator=(const BoardMessage& rhs)
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::DATA:
          set_data(rhs.get_data());
          break;

        case FieldNumber::INTERRUPT:
          set_interrupt(rhs.get_interrupt());
          break;

        default:
          break;
      }

      return *this;
    }

    BoardMessage& operator=(const BoardMessage&& rhs) noexcept
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::DATA:
          set_data(rhs.get_data());
          break;

        case FieldNumber::INTERRUPT:
          set_interrupt(rhs.get_interrupt());
          break;

        default:
          break;
      }

      return *this;
    }

    FieldNumber get_which_message() const { return which_message_; }

    static constexpr char const* DATA_NAME = "data";
    inline bool has_data() const
    {
      return FieldNumber::DATA == which_message_;
    }
    inline void clear_data()
    {
      if(FieldNumber::DATA == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.data_.~BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>();
      }
    }
    inline void set_data(const BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& value)
    {
      if(FieldNumber::DATA != which_message_)
      {
        init_message(FieldNumber::DATA);
      }
      message_.data_ = value;
    }
    inline void set_data(const BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>&& value)
    {
      if(FieldNumber::DATA != which_message_)
      {
        init_message(FieldNumber::DATA);
      }
      message_.data_ = value;
    }
    inline BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& mutable_data()
    {
      if(FieldNumber::DATA != which_message_)
      {
        init_message(FieldNumber::DATA);
      }
      return message_.data_;
    }
    inline const BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& get_data() const { return message_.data_; }
    inline const BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>& data() const { return message_.data_; }

    static constexpr char const* INTERRUPT_NAME = "interrupt";
    inline bool has_interrupt() const
    {
      return FieldNumber::INTERRUPT == which_message_;
    }
    inline void clear_interrupt()
    {
      if(FieldNumber::INTERRUPT == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.interrupt_.~BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>();
      }
    }
    inline void set_interrupt(const BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>& value)
    {
      if(FieldNumber::INTERRUPT != which_message_)
      {
        init_message(FieldNumber::INTERRUPT);
      }
      message_.interrupt_ = value;
    }
    inline void set_interrupt(const BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>&& value)
    {
      if(FieldNumber::INTERRUPT != which_message_)
      {
        init_message(FieldNumber::INTERRUPT);
      }
      message_.interrupt_ = value;
    }
    inline BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>& mutable_interrupt()
    {
      if(FieldNumber::INTERRUPT != which_message_)
      {
        init_message(FieldNumber::INTERRUPT);
      }
      return message_.interrupt_;
    }
    inline const BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>& get_interrupt() const { return message_.interrupt_; }
    inline const BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>& interrupt() const { return message_.interrupt_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      switch(which_message_)
      {
        case FieldNumber::DATA:
          if(has_data() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.data_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DATA), buffer, true);
          }
          break;

        case FieldNumber::INTERRUPT:
          if(has_interrupt() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.interrupt_.serialize_with_id(static_cast<uint32_t>(FieldNumber::INTERRUPT), buffer, true);
          }
          break;

        default:
          break;
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
          case FieldNumber::INTERRUPT:
            return_value = deserialize_message(id_tag, buffer, wire_type);
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
      clear_message();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::DATA:
          name = DATA_NAME;
          break;
        case FieldNumber::INTERRUPT:
          name = INTERRUPT_NAME;
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

      left_chars = to_string_message(left_chars, indent_level + 2, true);
  
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



      FieldNumber which_message_ = FieldNumber::NOT_SET;
      union message
      {
        message() {}
        ~message() {}
        BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH> data_;
        BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH> interrupt_;
      };
      message message_;

      void init_message(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_message_)
        {
          // First delete the old object in the oneof.
          clear_message();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::DATA:
            new(&message_.data_) BoundDataArray<BoardMessage_data_BoundDataArray_entry_REP_LENGTH, BoardMessage_data_BoundDataArray_entry_BoundData_buffer_IntArray_entry_REP_LENGTH>;
            break;

          case FieldNumber::INTERRUPT:
            new(&message_.interrupt_) BoundData<BoardMessage_interrupt_BoundData_buffer_IntArray_entry_REP_LENGTH>;
            break;

          default:
            break;
         }

         which_message_ = field_id;
      }

      void clear_message()
      {
        switch(which_message_)
        {
          case FieldNumber::DATA:
            ::EmbeddedProto::destroy_at(&message_.data_);
            break;
          case FieldNumber::INTERRUPT:
            ::EmbeddedProto::destroy_at(&message_.interrupt_);
            break;
          default:
            break;
        }
        which_message_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_message(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_message_)
        {
          init_message(field_id);
        }

        switch(which_message_)
        {
          case FieldNumber::DATA:
            return_value = message_.data_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::INTERRUPT:
            return_value = message_.interrupt_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_message();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_message(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_message_)
        {
          case FieldNumber::DATA:
            left_chars = message_.data_.to_string(left_chars, indent_level, DATA_NAME, first_field);
            break;
          case FieldNumber::INTERRUPT:
            left_chars = message_.interrupt_.to_string(left_chars, indent_level, INTERRUPT_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

template<
    uint32_t HostMessage_read_Read_pin_REP_LENGTH, 
    uint32_t HostMessage_write_Write_data_REP_LENGTH, 
    uint32_t HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH
>
class HostMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    HostMessage() = default;
    HostMessage(const HostMessage& rhs )
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::READ:
          set_read(rhs.get_read());
          break;

        case FieldNumber::WRITE:
          set_write(rhs.get_write());
          break;

        case FieldNumber::CONFIG:
          set_config(rhs.get_config());
          break;

        case FieldNumber::DECONFIG:
          set_deconfig(rhs.get_deconfig());
          break;

        case FieldNumber::DUMP:
          set_dump(rhs.get_dump());
          break;

        default:
          break;
      }

    }

    HostMessage(const HostMessage&& rhs ) noexcept
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::READ:
          set_read(rhs.get_read());
          break;

        case FieldNumber::WRITE:
          set_write(rhs.get_write());
          break;

        case FieldNumber::CONFIG:
          set_config(rhs.get_config());
          break;

        case FieldNumber::DECONFIG:
          set_deconfig(rhs.get_deconfig());
          break;

        case FieldNumber::DUMP:
          set_dump(rhs.get_dump());
          break;

        default:
          break;
      }

    }

    ~HostMessage() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      READ = 1,
      WRITE = 2,
      CONFIG = 3,
      DECONFIG = 4,
      DUMP = 5
    };

    HostMessage& operator=(const HostMessage& rhs)
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::READ:
          set_read(rhs.get_read());
          break;

        case FieldNumber::WRITE:
          set_write(rhs.get_write());
          break;

        case FieldNumber::CONFIG:
          set_config(rhs.get_config());
          break;

        case FieldNumber::DECONFIG:
          set_deconfig(rhs.get_deconfig());
          break;

        case FieldNumber::DUMP:
          set_dump(rhs.get_dump());
          break;

        default:
          break;
      }

      return *this;
    }

    HostMessage& operator=(const HostMessage&& rhs) noexcept
    {
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::READ:
          set_read(rhs.get_read());
          break;

        case FieldNumber::WRITE:
          set_write(rhs.get_write());
          break;

        case FieldNumber::CONFIG:
          set_config(rhs.get_config());
          break;

        case FieldNumber::DECONFIG:
          set_deconfig(rhs.get_deconfig());
          break;

        case FieldNumber::DUMP:
          set_dump(rhs.get_dump());
          break;

        default:
          break;
      }

      return *this;
    }

    FieldNumber get_which_message() const { return which_message_; }

    static constexpr char const* READ_NAME = "read";
    inline bool has_read() const
    {
      return FieldNumber::READ == which_message_;
    }
    inline void clear_read()
    {
      if(FieldNumber::READ == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.read_.~Read<HostMessage_read_Read_pin_REP_LENGTH>();
      }
    }
    inline void set_read(const Read<HostMessage_read_Read_pin_REP_LENGTH>& value)
    {
      if(FieldNumber::READ != which_message_)
      {
        init_message(FieldNumber::READ);
      }
      message_.read_ = value;
    }
    inline void set_read(const Read<HostMessage_read_Read_pin_REP_LENGTH>&& value)
    {
      if(FieldNumber::READ != which_message_)
      {
        init_message(FieldNumber::READ);
      }
      message_.read_ = value;
    }
    inline Read<HostMessage_read_Read_pin_REP_LENGTH>& mutable_read()
    {
      if(FieldNumber::READ != which_message_)
      {
        init_message(FieldNumber::READ);
      }
      return message_.read_;
    }
    inline const Read<HostMessage_read_Read_pin_REP_LENGTH>& get_read() const { return message_.read_; }
    inline const Read<HostMessage_read_Read_pin_REP_LENGTH>& read() const { return message_.read_; }

    static constexpr char const* WRITE_NAME = "write";
    inline bool has_write() const
    {
      return FieldNumber::WRITE == which_message_;
    }
    inline void clear_write()
    {
      if(FieldNumber::WRITE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.write_.~Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>();
      }
    }
    inline void set_write(const Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& value)
    {
      if(FieldNumber::WRITE != which_message_)
      {
        init_message(FieldNumber::WRITE);
      }
      message_.write_ = value;
    }
    inline void set_write(const Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>&& value)
    {
      if(FieldNumber::WRITE != which_message_)
      {
        init_message(FieldNumber::WRITE);
      }
      message_.write_ = value;
    }
    inline Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& mutable_write()
    {
      if(FieldNumber::WRITE != which_message_)
      {
        init_message(FieldNumber::WRITE);
      }
      return message_.write_;
    }
    inline const Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& get_write() const { return message_.write_; }
    inline const Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>& write() const { return message_.write_; }

    static constexpr char const* CONFIG_NAME = "config";
    inline bool has_config() const
    {
      return FieldNumber::CONFIG == which_message_;
    }
    inline void clear_config()
    {
      if(FieldNumber::CONFIG == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.config_.~Config();
      }
    }
    inline void set_config(const Config& value)
    {
      if(FieldNumber::CONFIG != which_message_)
      {
        init_message(FieldNumber::CONFIG);
      }
      message_.config_ = value;
    }
    inline void set_config(const Config&& value)
    {
      if(FieldNumber::CONFIG != which_message_)
      {
        init_message(FieldNumber::CONFIG);
      }
      message_.config_ = value;
    }
    inline Config& mutable_config()
    {
      if(FieldNumber::CONFIG != which_message_)
      {
        init_message(FieldNumber::CONFIG);
      }
      return message_.config_;
    }
    inline const Config& get_config() const { return message_.config_; }
    inline const Config& config() const { return message_.config_; }

    static constexpr char const* DECONFIG_NAME = "deconfig";
    inline bool has_deconfig() const
    {
      return FieldNumber::DECONFIG == which_message_;
    }
    inline void clear_deconfig()
    {
      if(FieldNumber::DECONFIG == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.deconfig_.~Deconfig();
      }
    }
    inline void set_deconfig(const Deconfig& value)
    {
      if(FieldNumber::DECONFIG != which_message_)
      {
        init_message(FieldNumber::DECONFIG);
      }
      message_.deconfig_ = value;
    }
    inline void set_deconfig(const Deconfig&& value)
    {
      if(FieldNumber::DECONFIG != which_message_)
      {
        init_message(FieldNumber::DECONFIG);
      }
      message_.deconfig_ = value;
    }
    inline Deconfig& mutable_deconfig()
    {
      if(FieldNumber::DECONFIG != which_message_)
      {
        init_message(FieldNumber::DECONFIG);
      }
      return message_.deconfig_;
    }
    inline const Deconfig& get_deconfig() const { return message_.deconfig_; }
    inline const Deconfig& deconfig() const { return message_.deconfig_; }

    static constexpr char const* DUMP_NAME = "dump";
    inline bool has_dump() const
    {
      return FieldNumber::DUMP == which_message_;
    }
    inline void clear_dump()
    {
      if(FieldNumber::DUMP == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.dump_.~Dump();
      }
    }
    inline void set_dump(const Dump& value)
    {
      if(FieldNumber::DUMP != which_message_)
      {
        init_message(FieldNumber::DUMP);
      }
      message_.dump_ = value;
    }
    inline void set_dump(const Dump&& value)
    {
      if(FieldNumber::DUMP != which_message_)
      {
        init_message(FieldNumber::DUMP);
      }
      message_.dump_ = value;
    }
    inline Dump& mutable_dump()
    {
      if(FieldNumber::DUMP != which_message_)
      {
        init_message(FieldNumber::DUMP);
      }
      return message_.dump_;
    }
    inline const Dump& get_dump() const { return message_.dump_; }
    inline const Dump& dump() const { return message_.dump_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      switch(which_message_)
      {
        case FieldNumber::READ:
          if(has_read() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.read_.serialize_with_id(static_cast<uint32_t>(FieldNumber::READ), buffer, true);
          }
          break;

        case FieldNumber::WRITE:
          if(has_write() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.write_.serialize_with_id(static_cast<uint32_t>(FieldNumber::WRITE), buffer, true);
          }
          break;

        case FieldNumber::CONFIG:
          if(has_config() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.config_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CONFIG), buffer, true);
          }
          break;

        case FieldNumber::DECONFIG:
          if(has_deconfig() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.deconfig_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DECONFIG), buffer, true);
          }
          break;

        case FieldNumber::DUMP:
          if(has_dump() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.dump_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DUMP), buffer, true);
          }
          break;

        default:
          break;
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
          case FieldNumber::READ:
          case FieldNumber::WRITE:
          case FieldNumber::CONFIG:
          case FieldNumber::DECONFIG:
          case FieldNumber::DUMP:
            return_value = deserialize_message(id_tag, buffer, wire_type);
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
      clear_message();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::READ:
          name = READ_NAME;
          break;
        case FieldNumber::WRITE:
          name = WRITE_NAME;
          break;
        case FieldNumber::CONFIG:
          name = CONFIG_NAME;
          break;
        case FieldNumber::DECONFIG:
          name = DECONFIG_NAME;
          break;
        case FieldNumber::DUMP:
          name = DUMP_NAME;
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

      left_chars = to_string_message(left_chars, indent_level + 2, true);
  
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



      FieldNumber which_message_ = FieldNumber::NOT_SET;
      union message
      {
        message() {}
        ~message() {}
        Read<HostMessage_read_Read_pin_REP_LENGTH> read_;
        Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH> write_;
        Config config_;
        Deconfig deconfig_;
        Dump dump_;
      };
      message message_;

      void init_message(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_message_)
        {
          // First delete the old object in the oneof.
          clear_message();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::READ:
            new(&message_.read_) Read<HostMessage_read_Read_pin_REP_LENGTH>;
            break;

          case FieldNumber::WRITE:
            new(&message_.write_) Write<HostMessage_write_Write_data_REP_LENGTH, HostMessage_write_Write_data_BoundData_buffer_IntArray_entry_REP_LENGTH>;
            break;

          case FieldNumber::CONFIG:
            new(&message_.config_) Config;
            break;

          case FieldNumber::DECONFIG:
            new(&message_.deconfig_) Deconfig;
            break;

          case FieldNumber::DUMP:
            new(&message_.dump_) Dump;
            break;

          default:
            break;
         }

         which_message_ = field_id;
      }

      void clear_message()
      {
        switch(which_message_)
        {
          case FieldNumber::READ:
            ::EmbeddedProto::destroy_at(&message_.read_);
            break;
          case FieldNumber::WRITE:
            ::EmbeddedProto::destroy_at(&message_.write_);
            break;
          case FieldNumber::CONFIG:
            ::EmbeddedProto::destroy_at(&message_.config_);
            break;
          case FieldNumber::DECONFIG:
            ::EmbeddedProto::destroy_at(&message_.deconfig_);
            break;
          case FieldNumber::DUMP:
            ::EmbeddedProto::destroy_at(&message_.dump_);
            break;
          default:
            break;
        }
        which_message_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_message(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_message_)
        {
          init_message(field_id);
        }

        switch(which_message_)
        {
          case FieldNumber::READ:
            return_value = message_.read_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::WRITE:
            return_value = message_.write_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::CONFIG:
            return_value = message_.config_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::DECONFIG:
            return_value = message_.deconfig_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::DUMP:
            return_value = message_.dump_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_message();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_message(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_message_)
        {
          case FieldNumber::READ:
            left_chars = message_.read_.to_string(left_chars, indent_level, READ_NAME, first_field);
            break;
          case FieldNumber::WRITE:
            left_chars = message_.write_.to_string(left_chars, indent_level, WRITE_NAME, first_field);
            break;
          case FieldNumber::CONFIG:
            left_chars = message_.config_.to_string(left_chars, indent_level, CONFIG_NAME, first_field);
            break;
          case FieldNumber::DECONFIG:
            left_chars = message_.deconfig_.to_string(left_chars, indent_level, DECONFIG_NAME, first_field);
            break;
          case FieldNumber::DUMP:
            left_chars = message_.dump_.to_string(left_chars, indent_level, DUMP_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace serial
#endif // SERIAL_H