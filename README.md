Результаты профилирования показывают, что реализация сложения по строкам работает значительно лучше, чем реализация сложения по столбцам. В первую очередь это связано с разницей в поведении кэша между двумя реализациями.

При построчном добавлении доступ к данным осуществляется последовательно, что хорошо согласуется с тем, как данные хранятся в памяти и как работает кеш. Это приводит к более высокой частоте попаданий в кэш и меньшему количеству промахов кэша.

С другой стороны, при добавлении по столбцам доступ к данным осуществляется непоследовательным образом. Это приводит к более низкой частоте попаданий в кэш и большему количеству промахов кэша, что значительно снижает производительность
