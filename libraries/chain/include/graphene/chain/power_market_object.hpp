/*#ifndef POWER_MARKET_OBJECT_HPP
#define POWER_MARKET_OBJECT_HPP

#endif // POWER_MARKET_OBJECT_HPP*/
#pragma once

#include <graphene/chain/protocol/operations.hpp>
#include <graphene/db/generic_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <vector>

namespace graphene
{
    namespace name
    {
        using namespace std;
        class databse;
        class power_market_category_object:public graphene::db::abstract_object<power_market_category_object>
        {
        public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = power_market_category_object_type;

            string                                              category_name;
            uint8_t                                             power_market_type;
            uint32_t                                            order_num;
            account_id_type                                     issuer;
            uint8_t                                             status = 0;
            time_point_sec                                      create_date_time;
        };

        struct by_issuer;
        struct by_power_market_type;

        using power_market_category_multi_index_type = multi_index_container<
            power_market_category_object,
            indexed_by<
                ordered_unique< tag<by_id>, member< object,object_id_type,&object::id> >,
                ordered_non_unique< tag<by_issuer>, member<power_market_category_object,account_id_type,&power_market_category_object::issuer> >,
                ordered_non_unique< tag<by_power_market_type>,
                    composite_key<
                        power_market_category_object,
                        member<power_market_category_object,uint8_t,&power_market_category_object::power_market_type>
                    >
                >
            >
        >;

        using power_market_category_index = generic_index<power_market_category_object,power_market_category_multi_index_type>;
    }
}

FC_REFLECT_DERIVED( graphene::chain::power_market_category_object,
                    (graphene::db::object),
                    (category_name)
                    (power_market_type)
                    (order_num)
                    (issuer)
                    (status)
                    (create_date_time)
        )
