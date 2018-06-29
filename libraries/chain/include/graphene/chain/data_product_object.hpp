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
        struct data_product_status_objcet
        {
            account_id_type     data_product;
            uint8_t              status = 0;
        };

        class data_product_object :public graphene::db::abstract_object<data_product_object>
        {
        public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = data_product_object_type;

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
            uint64_t                        commision = 0;
        };

        struct sort_data_product_object_by_create_date_time
        {
          bool operator () (const data_product_object &l ,const data_product_object &r)
          {
              return l.create_date_time >r.create_date_time;
          }
        };

        class data_product_search_results_object : public graphene::db::abstract_object<data_product_search_results_object>
        {
        public:
            static const uint8_t space_id = implementation_ids;
            static const uint8_t type_id = impl_data_product_search_result_object_type;

            uint64_t total = 0;
            vector <data_product_object> data;
        };

        class data_product_complain_object : public graphene::db::abstract_object<data_product_complain_object>
        {
        public:
            static const uint8_t space_id = protocol_ids;
            static const uint8_t type_id = data_product_complain_object_type;
            account_id_type                         requester;
            account_id_type                         datasource;
            string                                  data_product_request_id;
            //string                                  merchant_copyright_hash;
            //string                                  datasource_copyright_hash;
            time_point_sec                          create_date_time;
        };

        struct by_request_id{};
        struct by_create_date_time {};
        struct by_requester{};
        using data_production_mutil_index_type = multi_index_container<
        data_product_object,
        indexed_by<
        ordered_unique< tag<by_id>,member< object,object_id_type,&object::id> >,
        ordered_non_unique< tag<by_create_date_time> ,member<data_product_object,time_point_sec,&data_product_object::create_date_time> >,
        ordered_non_unique< tag<by_requester>,
            member<data_product_object,account_id_type,&data_product_object::requester>
        >,
        ordered_unique< tag<by_request_id> ,
            composite_key<
                data_product_object,
                member<data_product_object,string,&data_product_object::request_id >,
                member<data_product_object,time_point_sec,&data_product_object::create_date_time>
                  >,
                composite_key_compare<std::less<string>,std::less<time_point_sec> >
                >
             >
        >;

        using data_product_index = generic_index<data_product_object,data_production_mutil_index_type>;

        using data_production_complain_mutil_index_type = multi_index_container<
            data_product_complain_object,
            indexed_by<
                ordered_unique< tag<by_id>,member< object,object_id_type,&object::id> >,
                ordered_non_unique< tag< by_create_date_time >,member< data_product_complain_object, time_point_sec,&data_product_complain_object::create_date_time> >,
                ordered_unique< tag<by_request_id>, member<data_product_complain_object,string,&data_product_complain_object::data_product_request_id> >
            >
        >;
        using data_product_complain_index = generic_index<data_product_complain_object,data_production_complain_mutil_index_type>;
    }
}

FC_REFLECT( graphene::chain::data_product_status_objcet,
            (data_product)
            (status)
 )

FC_REFLECT_DERIVED( graphene::chain::data_product_complain_object,
            (graphene::db::object),
            (requester)
            (datasource)
            (data_product_request_id)
            (create_date_time)
        )

FC_REFLECT_DERIVED( graphene::chain::data_product_object,
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
                    (commision)
        )

FC_REFLECT_DERIVED( graphene::chain::data_product_search_results_object,
                    (graphene::db::object),
                    (total)
                    (data))
