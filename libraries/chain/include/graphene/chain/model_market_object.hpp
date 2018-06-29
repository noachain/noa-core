/*#ifndef MODEL_MARKET_H
#define MODEL_MARKET_H

#endif // MODEL_MARKET_H
*/
#pragma once
#include <graphene/chain/protocol/operations.hpp>
#include <graphene/db/generic_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <vector>

namespace graphene
{
    namespace  chain
    {
        using namespace std;
        class database;

        class model_market_category_object : public graphene::db::abstract_object<model_market_category_object>
        {
          public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = model_market_category_object_type;

            string                                      category_name;
            uint8_t                                     model_market_type;
            uint32_t                                    order_num;
            account_id_type                             issuer;
            uint8_t                                     status =0;
            time_point_sec                              create_date_time;
        };

        struct by_id_model{};
        struct by_issuer_model{};
        struct by_model_market_type{};

        using model_market_category_multi_index_type = multi_index_container<
            model_market_category_object,
            indexed_by<
                ordered_unique< tag<by_id_model> ,member<object,object_id_type,&object::id> >,
                ordered_non_unique< tag<by_issuer_model>,member<model_market_category_object,account_id_type,&model_market_category::issuer> >,
                ordered_non_unique< tag<by_model_market_type>,
                composite_key<
                    model_market_category_object,
                    member<model_market_category_object,uint8_t,&model_market_category_object::model_market_type>
                >
               >
            >
        >;

     using model_market_category_index = generic_index<model_market_category_object,model_market_category_multi_index_type>;
    }
}

FC_REFLECT_DERIVED( graphene::chain::model_market_category_object,
                    (graphene::db::object),
                    (category_name)
                    (model_market_type)
                    (order_num)
                    (issuer)
                    (status)
                    (create_date_time)
        )
