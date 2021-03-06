#include "RealmConfigurationAvailable.h"

//================
//DE/CONSTRUCTOR
//================


RealmConfigurationAvailable::RealmConfigurationAvailable(RealmConfigurationPropertyId id, QString key, QString defaultValue, RealmConfigurationValueType type, bool sharedWithClient)
{
    m_id = id;
    m_key = key;
    m_defaultValue = defaultValue;
    m_type = type;
    m_sharedWithClient = sharedWithClient;
}

RealmConfigurationAvailable::~RealmConfigurationAvailable()
{
}

//================
//GETTER
//================

RealmConfigurationPropertyId RealmConfigurationAvailable::GetId()
{
    return m_id;
}

QString RealmConfigurationAvailable::GetKey()
{
    return m_key;
}

QString RealmConfigurationAvailable::GetDefaultValue()
{
    return m_defaultValue;
}

RealmConfigurationValueType RealmConfigurationAvailable::GetType()
{
    return m_type;
}

bool RealmConfigurationAvailable::IsSharedWithClient()
{
    return m_sharedWithClient;
}

//================
//LOGIC
//================

bool RealmConfigurationAvailable::CheckValue(RealmConfigurationValueType type, QString value)
{
    //boolean
    switch(type)
    {
        case RealmConfigurationValueType::TYPE_BOOLEAN :
        {
            return (value == "true" || value == "false");
            break;
        }

        case RealmConfigurationValueType::TYPE_NUMBER :
        {
            bool conversionCheck;
            value.toInt(&conversionCheck);
            return conversionCheck;
            break;
        }

        case RealmConfigurationValueType::TYPE_NUMBERLIST :
        {
            QStringList valueList = value.split(";", QString::SkipEmptyParts);

            foreach (QString valueItem, valueList)
            {
                bool conversionCheck;
                valueItem.toInt(&conversionCheck);

                if(!conversionCheck) return false;
            }
            return true;
            break;
        }

        case RealmConfigurationValueType::TYPE_STRING :
        case RealmConfigurationValueType::TYPE_STRINGLIST:
        {
            return true;
            break;
        }

        default:
        {
            Log::Write(LOG_TYPE_ERROR, "No Check in function RealmConfigurationAvailable::CheckValue for ValueType %i", (int)type);
            return false;
            break;
        }
    }
}

bool RealmConfigurationAvailable::CheckValue(QString value)
{
    return RealmConfigurationAvailable::CheckValue(GetType(), value);
}
