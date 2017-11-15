/* Select last actual base_rate for position Employee (id = 1) */
select base_rate from base_rate_history           
    where position = 1 and change_date = (select max(change_date)
        from base_rate_history
        where position = 1);
