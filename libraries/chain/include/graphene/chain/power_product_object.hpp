/*#ifndef POWER_PRODUCT_OBJCT_H
#define POWER_PRODUCT_OBJCT_H

#endif // POWER_PRODUCT_OBJCT_H
*/
#pragma once
/*#ifndef DATA_PRODUCT_OPS_H
#define DATA_PRODUCT_OPS_H

#endif // DATA_PRODUCT_OPS_H
*/
#pragma once

#include <graphene/chain/protocol/operations.hpp>
#include <graphene/db/generic_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <vector>
namespace graphene
{
    namespace chain
    {
        using namespace std;
        class database;
        class model_market_object;
        struct power_product_status_objcet
        {
            account_id_type     power_product;
            uint8_t              status = 0;
        };

        class power_product_object :public graphene::db::abstract_object<power_product_object>
        {
        public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = power_product_object_type;

            string                          request_id;
            object_id_type                  product_id;
            string                          version;
            string                          params;
            uint8_t                         status =0;
            time_point_sec                  create_date_time;
            account_id_type                 requester;
            //fc::optional<data_market_id_type> data_market_id = fc::optional<data_market_id_type>();
            string                          memo;
            uint64_t                        product_pay = 0;
            uint64_t                        transaction_fee = 0;
            uint64_t                        commission = 0;
        };

        struct sort_power_product_object_by_create_date_time
        {
          bool operator () (const power_product_object &l ,const power_product_object &r)
          {
              return l.create_date_time >r.create_date_time;
          }
        };



        class power_product_search_results_object : public graphene::db::abstract_object<power_product_search_results_object>
        {
        public:
            static const uint8_t space_id = implementation_ids;
            static const uint8_t type_id = impl_power_product_search_result_object_type;

            uint64_t total = 0;
            vector <power_product_object> data;
        };

        class power_product_complain_object : public graphene::db::abstract_object<power_product_complain_object>
        {
        public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = power_product_complain_object_type;
            account_id_type                         requester;
            account_id_type                         powersource;
            string                                  power_product_request_id;
            //string                                  merchant_copyright_hash;
            //string                                  datasource_copyright_hash;
            time_point_sec                          create_date_time;
        };

        struct by_id_power{};
        struct by_request_id_power{};
        struct by_create_date_time_power {};
        struct by_requester_power{};
        using power_production_multi_index_type = multi_index_container<
        power_product_object,
        indexed_by<
        ordered_unique< tag<by_id_power>,member< object,object_id_type,&object::id> >,
        ordered_non_unique< tag<by_create_date_time_power> ,member<power_product_object,time_point_sec,&power_product_object::create_date_time> >,
        ordered_non_unique< tag<by_requester_power>,
            member<power_product_object,account_id_type,&power_product_object::requester>
        >,
        ordered_unique< tag<by_request_id_power> ,
            composite_key<
                power_product_object,
                member<power_product_object,string,&power_product_object::request_id >,
                member<power_product_object,time_point_sec,&power_product_object::create_date_time>
                  >,
                composite_key_compare<std::less<string>,std::less<time_point_sec> >
                >
             >
        >;

        using power_product_index = generic_index<power_product_object,power_production_multi_index_type>;

        using power_production_complain_mutil_index_type = multi_index_container<
            power_product_complain_object,
            indexed_by<
                ordered_unique< tag<by_id_power>,member< object,object_id_type,&object::id> >,
                ordered_non_unique< tag< by_create_date_time_power >,member< power_product_complain_object, time_point_sec,&power_product_complain_object::create_date_time> >,
                ordered_unique< tag<by_request_id_power>, member<power_product_complain_object,string,&power_product_complain_object::power_product_request_id> >
            >
        >;
        using power_product_complain_index = generic_index<power_product_complain_object,power_production_complain_mutil_index_type>;
    }
}

FC_REFLECT( graphene::chain::power_product_status_objcet,
            (power_product)
            (status)
 )

FC_REFLECT_DERIVED( graphene::chain::power_product_complain_object,
            (graphene::db::object),
            (requester)
            (powersource)
            (power_product_request_id)
            (create_date_time)
        )

FC_REFLECT_DERIVED( graphene::chain::power_product_object,
                    (graphene::db::object),
                    (request_id)
                    (product_id)
                    (version)
                    (params)
                    (status)
                    (create_date_time)
                    (requester)
                    (memo)
                    (product_pay)
                    (transaction_fee)
                    (commission)
        )

FC_REFLECT_DERIVED( graphene::chain::power_product_search_results_object,
                    (graphene::db::object),
                    (total)
                    (data)
                    )
