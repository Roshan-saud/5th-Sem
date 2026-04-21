<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html"/>

<xsl:template match="/">

<html>
<head>
    <title>Book List</title>
</head>

<body>

<h2 style="text-align:center;">Book List</h2>

<table border="1" style="border-collapse:collapse; width:70%; margin:auto;">

<tr style="background-color:black; color:white;">
    <th>Title</th>
    <th>Author</th>
    <th>Price</th>
    <th>ISBN</th>
</tr>

<xsl:for-each select="books/book">
<tr>
    <td><xsl:value-of select="title"/></td>
    <td><xsl:value-of select="author"/></td>
    <td><xsl:value-of select="price"/></td>
    <td><xsl:value-of select="isbn"/></td>
</tr>
</xsl:for-each>

</table>

</body>
</html>

</xsl:template>

</xsl:stylesheet>
