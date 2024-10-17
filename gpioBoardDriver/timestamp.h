/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: timestamp.proto
 */

// This file is generated. Please do not edit!
#ifndef TIMESTAMP_H
#define TIMESTAMP_H

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

namespace google {
namespace protobuf {

class Timestamp final: public ::EmbeddedProto::MessageInterface
{
  public:
    Timestamp() = default;
    Timestamp(const Timestamp& rhs )
    {
      set_seconds(rhs.get_seconds());
      set_nanos(rhs.get_nanos());
    }

    Timestamp(const Timestamp&& rhs ) noexcept
    {
      set_seconds(rhs.get_seconds());
      set_nanos(rhs.get_nanos());
    }

    ~Timestamp() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SECONDS = 1,
      NANOS = 2
    };

    Timestamp& operator=(const Timestamp& rhs)
    {
      set_seconds(rhs.get_seconds());
      set_nanos(rhs.get_nanos());
      return *this;
    }

    Timestamp& operator=(const Timestamp&& rhs) noexcept
    {
      set_seconds(rhs.get_seconds());
      set_nanos(rhs.get_nanos());
      return *this;
    }

    static constexpr char const* SECONDS_NAME = "seconds";
    inline void clear_seconds() { seconds_.clear(); }
    inline void set_seconds(const int64_t& value) { seconds_ = value; }
    inline void set_seconds(const int64_t&& value) { seconds_ = value; }
    inline int64_t& mutable_seconds() { return seconds_.get(); }
    inline const int64_t& get_seconds() const { return seconds_.get(); }
    inline int64_t seconds() const { return seconds_.get(); }

    static constexpr char const* NANOS_NAME = "nanos";
    inline void clear_nanos() { nanos_.clear(); }
    inline void set_nanos(const int32_t& value) { nanos_ = value; }
    inline void set_nanos(const int32_t&& value) { nanos_ = value; }
    inline int32_t& mutable_nanos() { return nanos_.get(); }
    inline const int32_t& get_nanos() const { return nanos_.get(); }
    inline int32_t nanos() const { return nanos_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != seconds_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = seconds_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SECONDS), buffer, false);
      }

      if((0 != nanos_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = nanos_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NANOS), buffer, false);
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
          case FieldNumber::SECONDS:
            return_value = seconds_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NANOS:
            return_value = nanos_.deserialize_check_type(buffer, wire_type);
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
      clear_seconds();
      clear_nanos();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SECONDS:
          name = SECONDS_NAME;
          break;
        case FieldNumber::NANOS:
          name = NANOS_NAME;
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

      left_chars = seconds_.to_string(left_chars, indent_level + 2, SECONDS_NAME, true);
      left_chars = nanos_.to_string(left_chars, indent_level + 2, NANOS_NAME, false);
  
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


      EmbeddedProto::int64 seconds_ = 0;
      EmbeddedProto::int32 nanos_ = 0;

};

} // End of namespace protobuf
} // End of namespace google
#endif // TIMESTAMP_H